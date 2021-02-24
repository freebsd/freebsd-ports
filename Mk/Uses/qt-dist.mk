# $FreeBSD$
#
# There are three Qt related USES files with different access to Qt.
#   - qmake: The port requires Qt's qmake to build -- creates the configure target
#            - auto includes qt.mk
#   - qt-dist: The port is a port for an part of Qt5
#            - auto inclues qt.mk
#   - qt.mk  - Dependency handling. USE_QT=foo bar
#
#
# Usage
#    qt-dist:<version>[,yes|modulename]
#
# MAINTAINER:	kde@FreeBSD.org

.if !defined(_QT_DIST_MK_INCLUDED)
_QT_DIST_MK_INCLUDED=	qt-dist.mk

# Suck in qt.mk and qmake.mk
qt_ARGS?=	# empty
.include "${USESDIR}/qt.mk"
qmake_ARGS?=	# empty
.include "${USESDIR}/qmake.mk"

# Supported distribution arguments
_QT5_DISTS=		3d activeqt androidextras base charts connectivity datavis3d \
			declarative doc gamepad graphicaleffects imageformats location \
			lottie macextras multimedia networkauth purchasing quick3d quickcontrols \
			quickcontrols2 quicktimeline remoteobjects script scxml sensors serialbus \
			serialport speech svg tools translations virtualkeyboard wayland \
			webchannel webengine webglplugin websockets webview winextras \
			x11extras xmlpatterns
_QT_DISTS=		${_QT${_QT_VER}_DISTS}

# We only accept one item as an argument. The fetch target further below works
# around this.
_QT_DIST=		# empty
.  for dist in ${_QT_DISTS:O:u}
.    if ${qt-dist_ARGS:M${dist}}
.      if empty(_QT_DIST)
_QT_DIST=		${dist}
.      else
IGNORE=		cannot be installed: different Qt dists specified via qt-dist:[${qt-dist_ARGS:S/ /,/g}]
.      endif
.    endif
.  endfor

# Fall back to sensible defaults for _QT_DIST
.  if empty(_QT_DIST)
.    if ${_QT_VER:M5}
_QT_DIST=		${PORTNAME} # don't force qt-dist to be set for Qt5 ports which 75% of time are ${PORTNAME}
.    endif
.  endif

# Check validitiy
.  if empty(_QT_DISTS:M${_QT_DIST})
IGNORE=			Unsupported qt-dist ${_QT_DIST} for qt:${_QT_VER}
.  endif
################################################################################

# Set standard bsd.port.mk variables
MASTER_SITES=		${MASTER_SITE_QT}
DISTINFO_FILE?=		${PORTSDIR}/devel/${_QT_RELNAME}/distinfo

LICENSE?=		LGPL21

.  if !exists(${PKGDIR}/pkg-descr)
DESCR?=			${PORTSDIR}/devel/${_QT_RELNAME}/pkg-descr
.  endif

# Stage support.
DESTDIRNAME=		INSTALL_ROOT

.  if ${_QT_VER:M5}
MASTER_SITE_SUBDIR?=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/submodules/
# www/qt5-webengine hackery: The tarballs of 5.9.5 had a different naming scheme.
.    if ${QT5_VERSION} == "5.9.5"
DISTNAME=		${_QT_DIST:S,^,qt,:S,$,-opensource-src-${DISTVERSION},}
.    else
DISTNAME=		${_QT_DIST:S,^,qt,:S,$,-everywhere-src-${DISTVERSION},}
.    endif
DISTFILES=		${DISTNAME:S,$,${EXTRACT_SUFX},}
DIST_SUBDIR=		KDE/Qt/${_QT_VERSION}

# Qt (at least when used with qmake) has a tendency to overlink: some libraries
# have dependencies on others in the mkspec configurations and the latter are
# always passed to the linker even if they are not actually used. By passing
# --as-needed to the linker by default when building the Qt ports we do not
# have to declare a lot of unnecessary dependencies in USE_QT5.
LDFLAGS+=		-Wl,--as-needed

.    if ${.TARGETS:Mmakesum} || ${.TARGETS:Mfetch} && \
	defined(DISABLE_SIZE) && defined(NO_CHECKSUM)
# Ensure that the "makesum" target (with its inner "fetch" one) uses
# devel/qt*/distinfo for every port.
.      if ${DISTINFO_FILE:H} == ${PORTSDIR}/devel/${_QT_RELNAME}
_QT_DIST=		${_QT5_DISTS}
.      endif
.    endif

# Qt5's tarballs are xz compressed.
.    if empty(USES:Mtar)
EXTRACT_SUFX?=		.tar.xz
.    endif

.    if ${_QT_DIST} == "base" && ${PORTNAME} != "qmake"
# Qt configure requires pkg-config to detect dependencies.
.include "${USESDIR}/pkgconfig.mk"
.    endif

# -nomake is only used by qtbase's configure script.
# Other ports from other Qt modules will automatically build examples and
# tests if the directories exist because of mkspecs/features/qt_parts.prf.
EXTRACT_AFTER_ARGS?=	${DISTNAME:S,$,/examples,:S,^,--exclude ,} \
			${DISTNAME:S,$,/tests,:S,^,--exclude ,} \
			--no-same-owner --no-same-permissions
.  endif # ! ${_QT_VER:M5}

CONFIGURE_ENV+=		MAKE="${MAKE:T}"

CONFIGURE_ARGS+=	-opensource -confirm-license \
			-no-pch \
			-prefix ${PREFIX} \
			-bindir ${PREFIX}/${QT_BINDIR_REL} \
			-headerdir ${PREFIX}/${QT_INCDIR_REL} \
			-libdir ${PREFIX}/${QT_LIBDIR_REL} \
			-plugindir ${PREFIX}/${QT_PLUGINDIR_REL} \
			-importdir ${PREFIX}/${QT_IMPORTDIR_REL} \
			-datadir ${PREFIX}/${QT_DATADIR_REL} \
			-docdir ${PREFIX}/${QT_DOCDIR_REL} \
			-translationdir ${PREFIX}/${QT_L10NDIR_REL} \
			-sysconfdir ${PREFIX}/${QT_ETCDIR_REL}

.  if ${_QT_VER:M5}
CONFIGURE_ARGS+=	-nomake examples -nomake tests \
			-platform ${QMAKESPECNAME} \
			-archdatadir ${PREFIX}/${QT_ARCHDIR_REL} \
			-libexecdir ${PREFIX}/${QT_LIBEXECDIR_REL} \
			-qmldir ${PREFIX}/${QT_QMLDIR_REL} \
			-examplesdir ${PREFIX}/${QT_EXAMPLEDIR_REL} \
			-testsdir ${PREFIX}/${QT_TESTDIR_REL}

.    if ${ARCH} == i386 && empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=	-no-sse2
.    endif

# Work around a bug in current binutils, where the gold linker creates
# duplicate symbols. See pr 218187. Disable the gold-linker for Qt5 ports.
CONFIGURE_ARGS+=	-no-use-gold-linker
# Pass -recheck-all so that multiple calls to the configure script really
# re-run all checks.
CONFIGURE_ARGS+=	-recheck-all
.  endif # ${_QT_VER:M5}

.  if defined(WANT_QT_DEBUG) || defined(WITH_DEBUG)
WITH_DEBUG=		yes
STRIP=			# It's done prior to bsd.qt.mk inclusion.
CONFIGURE_ARGS+=	-debug -separate-debug-info
# Override configuration in global qconfig.pri.
QMAKE_ARGS+=		QT_CONFIG+="debug separate_debug_info" \
			QT_CONFIG-="release"
.  else
CONFIGURE_ARGS+=	-release -no-separate-debug-info
QMAKE_ARGS+=		QT_CONFIG+="release" \
			QT_CONFIG-="debug separate_debug_info"
.  endif # defined(WANT_QT_DEBUG) || defined(WITH_DEBUG)

.  if defined(WANT_QT_VERBOSE_CONFIGURE)
CONFIGURE_ARGS+=	-verbose
.  endif

.  if ${_QT_DIST} == "base"
_EXTRA_PATCHES_QT5=	${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_features_create__cmake.prf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_features_qt__module.prf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_common_bsd_bsd.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_freebsd-clang_qmake.conf
.        if ${ARCH:Mmips*} || (${ARCH:Mpowerpc*} && !exists(/usr/bin/clang)) || ${ARCH} == sparc64
_EXTRA_PATCHES_QT5+=	${PORTSDIR}/devel/${_QT_RELNAME}/files/extra-patch-mkspecs_common_g++-base.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extra-patch-mkspecs_common_gcc-base.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_freebsd-g++_qmake.conf
USE_GCC=		yes
.    endif
EXTRA_PATCHES?=		${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-configure \
			${_EXTRA_PATCHES_QT5}
.  endif #  ${_QT_DIST} == "base"

# Override settings installed in qconfig.h and *.pri files. The flags will be
# installed along with the port, but have to be passed as arguments while
# building the port itself. Flags prefixed with "-" (e.g., "-CUPS" and "-cups")
# are needed to disable some features.
.  if !defined(${QT_MODNAME}) || empty(${QT_MODNAME})
# Used for both qconfig-*.h and qt_config_*.pri; it can't be empty.
QT_MODNAME=		${PORTNAME}
.  endif
QT_DEFINES?=		# For qconfig.h flags (without "QT_" prefix).
QT_CONFIG?=		# For *.pri files QT_CONFIG flags.
.  if ${QT_DEFINES}
QMAKE_ARGS+=		DEFINES+="${QT_DEFINES:O:u:C/^([^-])/QT_\1/:C/^-/QT_NO_/:O}"
.  endif #  ${QT_DEFINES}
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall
PKGINSTALL=		${WRKDIR}/pkg-install
.  if ${QT_CONFIG:N-*}
QMAKE_ARGS+=		QT_CONFIG+="${QT_CONFIG:N-*:O:u}"
.  endif
.  if ${QT_CONFIG:M-*}
QMAKE_ARGS+=		QT_CONFIG-="${QT_CONFIG:M-*:O:u:C/^-//}"
.  endif

# Add a RUN_DEPENDS on misc/qtchooser to select the binaries.
# The binaries of both supported Qt versions are installed to
# ${LOCALBASE}/lib/qt${_QT_VER}/bin. The port misc/qtchooser installs
# wrapper binaries into ${LOCALBASE}/bin, and chooses the correct
# one depending on the value of QT_SELECT (which we pass to both
# CONFIGURE_ENV and MAKE_ENV). Therefore make all QT_DIST ports
# RUN_DEPEND on it.
RUN_DEPENDS+=		qtchooser:misc/qtchooser

PLIST_SUB+=		SHORTVER=${DISTVERSION:R} \
			FULLVER=${DISTVERSION:C/-.*//}

# Handle additional PLIST directories, which should only be used for Qt-dist ports.
.  for dir in CMAKE ETC
# Export QT_CMAKEDIR and QT_ETCDIR.
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.  endfor


.  if ${_QT_VER:M5}
.    if ${_QT_DIST} == "base"
# qtbase requires some tools to be symlinked to the build directory.
_QT_TOOLS=		# empty
.      if ${PORTNAME} != "qmake"
_QT_TOOLS+=		${QMAKE}
.      endif
.      if ${PORTNAME} != "buildtools"
_QT_TOOLS+=		${MOC} ${RCC}
.      endif
.      if ${PORTNAME} != "qdoc"
_QT_TOOLS+=		qdoc
.      endif
.      if ${PORTNAME} != "dbus"
_QT_TOOLS+=		qdbuscpp2xml qdbusxml2cpp
.      endif
.      if ${PORTNAME} != "widgets"
_QT_TOOLS+=		${UIC}
.      endif

# The list of QtBase components that need to be linked into WRKSRC/lib for
# other QtBase ports. See below.
_QT5_BASE=		core dbus gui network sql widgets
_QT5_ADDITIONAL_LINK?=	# Ensure definition

.if ${_QT_VER:M5}
post-patch: gcc-post-patch
gcc-post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/mkspecs/common/gcc-base.conf \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	${REINPLACE_CMD} 's|%%GCC_DEFAULT%%|${GCC_DEFAULT}|g' \
		${WRKSRC}/mkspecs/common/gcc-base.conf \
		${WRKSRC}/mkspecs/common/g++-base.conf \
		${WRKSRC}/mkspecs/common/bsd/bsd.conf \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
.endif

pre-configure: qtbase-pre-configure
qtbase-pre-configure:
.      for tool in ${_QT_TOOLS}
	@${TEST} -e ${QT_BINDIR}/${tool:T} && \
		${LN} -sf ${QT_BINDIR}/${tool:T} ${CONFIGURE_WRKSRC}/bin/${tool:T} || \
		${TRUE}
.      endfor

# The following is a fix for the inplace upgrade problem we faced (see
# QTBUG-40825 and ports bugs 194088, 195105 and 198720) previously,
# which previously was adressed by making sure, that ${LOCALBASE}/lib, which
# would often gets added by pkgconf for the dependencies, was passed after
# ${WRKSRC}/lib.
# * We fix the inplace upgrade problem by moving the Qt5 libraries into
#   ${LOCALBASE}/lib/qt5. Therefore a -L${LOCALBASE}/lib does no harm anymore.
# * However, this means, that the ports belonging to the split up QtBase package
#   now no longer can find their depending QtBase libraries. We fix this by
#   linking these into ${CONFIGURE_WRKSRC}/lib if the given QtBase port depends
#   on them.
.      if ${_QT_DIST:Mbase}
.        for basedep in ${_QT5_BASE}
.          if ! empty(USE_QT:M${basedep})
	${LN} -sf ${QT_LIBDIR}/${${basedep}_LIB} ${CONFIGURE_WRKSRC}/lib
.          endif
.        endfor
.      endif

#
# **** THIS PART IS OBSOLETE FOR THE NEXT QT UPGRADE ****
#
# Add ${LOCALBASE}/lib to DEFAULT_LIBDIRS, which we use to filter out
# certain paths from pkg-config calls (see the explanation in
# devel/qt5/files/patch-configure) as well as for setting
# QMAKE_DEFAULT_LIBDIR in mkspecs/qconfig.pri. Part of the solution for
# ports/194088.
post-patch: qtbase-post-patch
qtbase-post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/mkspecs/common/bsd/bsd.conf \
		${WRKSRC}/mkspecs/freebsd-clang/qmake.conf

.      if ${PORTNAME} != "qmake"
_QMAKE=			${CONFIGURE_WRKSRC}/bin/qmake
.      endif
.    endif

pre-configure: qt5-pre-configure
qt5-pre-configure:
# Qt 5.3.2 introduced a check in mkspecs/features/create_cmake.prf that
# requires tests/auto/cmake to be present, otherwise the configure stage will
# fail.
# Since we cannot extract tests/auto/cmake/ and exclude tests/ at the same
# time, we have to disable the check in a cache file (the only way to get this
# value through to the configure script in qtbase).
	${MKDIR} ${CONFIGURE_WRKSRC}
	${ECHO_CMD} 'CMAKE_MODULE_TESTS = -' > ${CONFIGURE_WRKSRC}/.qmake.cache
#
# **** THIS PART IS OBSOLETE FOR THE NEXT QT UPGRADE ****
#
# We piggyback on QMAKE_LIBDIR_FLAGS to make sure -L${WRKSRC}/lib is passed to
# the linker before -L/usr/local/lib. By default, the opposite happens, which
# is a problem when a Qt port is being upgraded, since an existing library
# would end up being picked up instead of those built in ${WRKSRC}/lib. Since
# qmake appends the value of QMAKE_LIBDIR to QMAKE_LIBDIR_FLAGS, we can use the
# latter to get the linker path order right. qmake is smart enough to strip
# occurrences of ${WRKSRC}/lib from .pc and .prl files when installing them.
# See QTBUG-40825 and ports bugs 194088, 195105 and 198720.
	${ECHO_CMD} 'QMAKE_LIBDIR_FLAGS = -L${CONFIGURE_WRKSRC}/lib' >> ${CONFIGURE_WRKSRC}/.qmake.cache
	${ECHO_CMD} 'QMAKE_DEFAULT_LIBDIRS += ${LOCALBASE}/lib /usr/lib /lib' >> ${CONFIGURE_WRKSRC}/.qmake.cache
	${ECHO_CMD} 'QMAKE_DEFAULT_INCDIRS += ${LOCALBASE}/include /usr/include' >> ${CONFIGURE_WRKSRC}/.qmake.cache

# Allow linking of further libraries to the configure directory.
.    if !empty(_QT5_ADDITIONAL_LINK)
.      for dep in ${_QT5_ADDITIONAL_LINK}
	${MKDIR} ${CONFIGURE_WRKSRC}/lib
.        if ! empty(USE_QT:M${dep})
	${LN} -sf ${QT_LIBDIR}/${qt-${dep}_LIB} ${CONFIGURE_WRKSRC}/lib
.        endif
.      endfor
.    endif

.    if ${QT_DEFINES:N-*}
# There **are** defines, so we need to **add** this port to the
# qconfig-modules.h header; make @need_add empty and comment out
# the @need_remove lines in the script (see below in qt-post-install).
# If there are no defines, do it the other way around.
_sub_need_add=
_sub_need_remove=	\#\#
.    else
_sub_need_add=		\#\#
_sub_need_remove=	
.    endif
# Handle misc/qtchooser wrapper installation and deinstallation
# If a port installs Qt version-specific binaries (e.g. "designer" which 
# existed as a Qt4 application and exists as a Qt5 application and will 
# probably be a Qt6 application) which should have a qtchooser-based wrapper, 
# the port should set `QT_BINARIES=yes`.
.    if defined(QT_BINARIES)
_sub_need_bin=
.    else
_sub_need_bin=		\#\#
.    endif
.    if ${QT_MODNAME} == core
# QtCore (e.g. devel/qt5-core) is the one that starts the header,
# and is also the one that can clean it up when deinstalled.
_sub_need_clean=	
.    else
_sub_need_clean=	\#\#
.    endif
post-install: qt-post-install
qt-post-install:
# We can't use SUB_FILES with the shared pkg-change.in.
# We need it to be a script instead of a group of @unexecs.
# Do two steps of processing -- introducing the Qt variables,
# and replacing the @tags with comment (or nothing) characters
# according to the port's settings -- in one sed and write
# to pkg-change.tmp. Then split it up and minify for the
# install and deinstall step.
	@${SED} -e 's,%%QT_MODNAME%%,${QT_MODNAME},g' \
		-e 's,%%QT_INCDIR%%,${QT_INCDIR},g' \
		-e 's,@need_add,${_sub_need_add},' \
		-e 's,@need_remove,${_sub_need_remove},' \
		-e 's,@need_clean,${_sub_need_clean},' \
		-e 's,@need_bin,${_sub_need_bin},' \
		${PORTSDIR}/devel/${_QT_RELNAME}/${FILESDIR:T}/pkg-change.in > \
		${WRKDIR}/pkg-change.tmp
	@${SED} -e 's,@install,,' -e 's,@deinstall,##,' ${WRKDIR}/pkg-change.tmp | ${SED} -e '/##/d' > ${PKGINSTALL}
	@${SED} -e 's,@install,##,' -e 's,@deinstall,,' ${WRKDIR}/pkg-change.tmp | ${SED} -e '/##/d' > ${PKGDEINSTALL}
	# Drop all leading spaces in the script, to minify
	@${REINPLACE_CMD} 's/^  *//' ${PKGINSTALL} ${PKGDEINSTALL}
.    if ${QT_DEFINES:N-*}
	@${MKDIR} ${STAGEDIR}${QT_INCDIR}/QtCore/modules
	@${ECHO_CMD} -n \
		> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
.      for def in ${QT_DEFINES:N-*:O:u:C/=.*$//}
	@${ECHO_CMD} "#if !defined(QT_${def}) && !defined(QT_NO_${def})" \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
	${ECHO_CMD} "# define QT_${def}" \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
	@${ECHO_CMD} "#endif" \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
	@${ECHO_CMD} \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
.      endfor
	@${ECHO_CMD} "${PREFIX}/${QT_INCDIR_REL}/QtCore/modules/qconfig-${QT_MODNAME}.h" \
		>> ${TMPPLIST}
.    endif # ${QT_DEFINES:N-*}
.    if ${QT_CONFIG:N-*}
	@${MKDIR} ${STAGEDIR}${QT_MKSPECDIR}/modules
	${ECHO_CMD} "QT_CONFIG += ${QT_CONFIG:N-*:O:u}" \
		> ${STAGEDIR}${QT_MKSPECDIR}/modules/qt_config_${QT_MODNAME}.pri
	@${ECHO_CMD} "${PREFIX}/${QT_MKSPECDIR_REL}/modules/qt_config_${QT_MODNAME}.pri" \
		>> ${TMPPLIST}
.    endif # ${QT_CONFIG:N-*}
.  endif # M5
.endif # defined(_QT_DIST_MK_INCLUDED)
