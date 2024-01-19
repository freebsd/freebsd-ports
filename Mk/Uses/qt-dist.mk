# There are three Qt related USES files with different access to Qt.
#   - qmake: The port requires Qt's qmake to build -- creates the configure target
#            - auto includes qt.mk
#   - qt-dist: The port is a port for a part of Qt
#            - auto includes qt.mk
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
_COMMON_DISTS=		3d base charts connectivity datavis3d declarative imageformats location multimedia \
			networkauth quick3d quicktimeline remoteobjects scxml sensors \
			serialbus serialport speech svg tools translations virtualkeyboard \
			wayland webchannel webengine websockets webview
_QT5_DISTS=		gamepad graphicaleffects quickcontrols \
			quickcontrols2 script webglplugin \
			x11extras xmlpatterns
_QT6_DISTS=		5compat coap doc graphs httpserver languageserver lottie positioning \
			quick3dphysics quickeffectmaker shadertools

_QT_DISTS=		${_COMMON_DISTS} \
			${_QT${_QT_VER}_DISTS}

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
_QT_DIST=		${PORTNAME} # don't force qt-dist to be set for Qt5 ports which 75% of time are ${PORTNAME}
.  endif

# Check validitiy
.  if empty(_QT_DISTS:M${_QT_DIST})
IGNORE=			Unsupported qt-dist ${_QT_DIST} for qt:${_QT_VER}
.  endif
################################################################################

# Set standard bsd.port.mk variables.
LICENSE?=		LGPL21
WWW?=		https://www.qt.io/

.  if !exists(${PKGDIR}/pkg-descr)
DESCR?=			${PORTSDIR}/devel/${_QT_RELNAME}/pkg-descr
.  endif

# Stage support.
_QT5_DESTDIRNAME=	INSTALL_ROOT
_QT6_DESTDIRNAME=	DESTDIR
DESTDIRNAME=		${_QT${_QT_VER}_DESTDIRNAME}

# Qt's tarballs are xz compressed.
.  if empty(USES:Mtar)
EXTRACT_SUFX?=		.tar.xz
.  endif

# Qt5 specific master sites
_QT5_MASTER_SITES_kde=		LOCAL
_QT5_MASTER_SITE_SUBDIR_kde=	kde/KDE/Qt/${_QT_VERSION}
_QT5_MASTER_SITES=		${MASTER_SITE_QT}
_QT5_MASTER_SITE_SUBDIR=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/submodules/
# Qt6 specific master sites
_QT6_MASTER_SITES=		${MASTER_SITE_QT}
_QT6_MASTER_SITE_SUBDIR=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/submodules \
				official_releases/additional_libraries/${_QT_VERSION:R}/${_QT_VERSION}/
# Qt5 specific distnames
.  if ${_QT_DIST} == webengine
_QT5_DISTNAME=			${_QT_DIST:S,^,qt,:S,$,-everywhere-opensource-src-${DISTVERSION},}
.  else
_QT5_DISTNAME=			${_QT_DIST:S,^,qt,:S,$,-everywhere-src-${DISTVERSION},}
.  endif
_QT5_DISTNAME_kde=		${_QT_DIST:S,^,kde-qt,:S,$,-${DISTVERSION},}
# Qt6 specific distnames
_QT6_DISTNAME=			${_QT_DIST:S,^,qt,:S,$,-everywhere-src-${DISTVERSION},}

# Effective master sites and distfile values
# net/qt6-coap has no submodule distfile and uses USE_GITHUB
.  if ${_QT_DIST} != coap
MASTER_SITES=			${_QT${_QT_VER}_MASTER_SITES${_KDE_${_QT_DIST}:D_kde}}
MASTER_SITE_SUBDIR=		${_QT${_QT_VER}_MASTER_SITE_SUBDIR${_KDE_${_QT_DIST}:D_kde}}
DISTNAME=			${_QT${_QT_VER}_DISTNAME${_KDE_${_QT_DIST}:D_kde}}
DISTFILES=			${DISTNAME:S,$,${EXTRACT_SUFX},}
.  endif
DIST_SUBDIR=			KDE/Qt/${_QT_VERSION}

.  if ${_QT_VER:M5}
# KDE maintains a repository with a patched Qt5 distribution.
_KDE_3d=		0
_KDE_base=		148
_KDE_charts=		0
_KDE_connectivity=	6
_KDE_datavis3d=		0
_KDE_declarative=	32
_KDE_gamepad=		0
_KDE_graphicaleffects=	0
_KDE_imageformats=	12
_KDE_location=		6
_KDE_multimedia=	2
_KDE_networkauth=	0
_KDE_quick3d=		1
_KDE_quickcontrols=	0
_KDE_quickcontrols2=	5
_KDE_quicktimeline=	0
_KDE_remoteobjects=	0
_KDE_script=		0
_KDE_script_ORIGIN_TAG=	v5.15.16-lts
_KDE_script_VERSION=	5.15.16
_KDE_scxml=		0
_KDE_sensors=		0
_KDE_serialbus=		0
_KDE_serialport=	0
_KDE_speech=		1
_KDE_svg=		6
_KDE_tools=		4
_KDE_translations=	0
_KDE_virtualkeyboard=	0
_KDE_wayland=		60
_KDE_webchannel=	3
_KDE_webengine=			5
_KDE_webengine_BRANCH=		5.15
_KDE_webengine_ORIGIN_TAG=	v5.15.16-lts
_KDE_webengine_VERSION=		5.15.16
_KDE_webglplugin=	0
_KDE_websockets=	2
_KDE_webview=		0
_KDE_x11extras=		0
_KDE_xmlpatterns=	0

.    if defined(_KDE_${_QT_DIST})
.      if defined(_KDE_${_QT_DIST}_ORIGIN_TAG)
_KDE_${_QT_DIST}_BRANCH?=	${_KDE_${_QT_DIST}_VERSION}
.      else
_KDE_${_QT_DIST}_BRANCH=	kde/5.15
COMMENT+=			(KDE patched)
.      endif
QT5_KDE_PATCH=		p${_KDE_${_QT_DIST}}
_KDE_${_QT_DIST}_VERSION?=	${_QT_VERSION}
_KDE_${_QT_DIST}_ORIGIN_TAG?=	v${_KDE_${_QT_DIST}_VERSION}-lts-lgpl
.    else
QT5_KDE_PATCH=		#
.    endif
.  endif # ${_QT_VER:M5}

# Environment setup for Qt5
.  if ${_QT_VER:M5}
# Qt (at least when used with qmake) has a tendency to overlink: some libraries
# have dependencies on others in the mkspec configurations and the latter are
# always passed to the linker even if they are not actually used. By passing
# --as-needed to the linker by default when building the Qt ports we do not
# have to declare a lot of unnecessary dependencies in USE_QT5.
LDFLAGS+=		-Wl,--as-needed

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

# Build setup for Qt6
.  if ${_QT_VER:M6}
CMAKE_ARGS+=		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
			-DINSTALL_BINDIR=${PREFIX}/${QT_BINDIR_REL} \
			-DINSTALL_PUBLICBINDIR=${PREFIX}/bin \
			-DINSTALL_LIBDIR=${PREFIX}/${QT_LIBDIR_REL} \
			-DINSTALL_LIBEXECDIR=${PREFIX}/${QT_LIBEXECDIR_REL} \
			-DINSTALL_DOCDIR=${PREFIX}/${QT_DOCDIR_REL} \
			-DINSTALL_ARCHDATADIR=${PREFIX}/${QT_ARCHDIR_REL} \
			-DINSTALL_DATADIR=${PREFIX}/${QT_DATADIR_REL} \
			-DINSTALL_INCLUDEDIR=${PREFIX}/${QT_INCDIR_REL} \
			-DINSTALL_MKSPECSDIR=${PREFIX}/${QT_MKSPECDIR_REL} \
			-DINSTALL_EXAMPLESDIR=${PREFIX}/${QT_EXAMPLEDIR_REL} \
			-DINSTALL_DESCRIPTIONSDIR=${PREFIX}/${QT_DESCRIPTIONSDIR_REL} \
			-DQT_QMAKE_TARGET_MKSPEC:String=freebsd-clang \
			--log-level=TRACE
.  endif

# Build setup for Qt5
.  if ${_QT_VER:M5}
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
			-sysconfdir ${PREFIX}/${QT_ETCDIR_REL} \
			-nomake examples -nomake tests \
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
.    if ${ARCH:Mmips*} || (${ARCH:Mpowerpc*} && !exists(/usr/bin/clang))
_EXTRA_PATCHES_QT5+=	${PORTSDIR}/devel/${_QT_RELNAME}/files/extra-patch-mkspecs_common_g++-base.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extra-patch-mkspecs_common_gcc-base.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_freebsd-g++_qmake.conf
USE_GCC=		yes
.    elif ${ARCH} == armv7 || ${ARCH} == powerpc
_EXTRA_PATCHES_QT5+=	${PORTSDIR}/devel/${_QT_RELNAME}/files/extra-patch-mkspecs_common_g++-base.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extra-patch-mkspecs_common_gcc-base.conf \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_freebsd-g++_qmake.conf
.    endif
.    if ${_QT_VER:M5}
EXTRA_PATCHES?=		${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-configure \
			${PORTSDIR}/devel/${_QT_RELNAME}/files/extrapatch-sync.profiles \
			${_EXTRA_PATCHES_QT5}
.    endif # ${_QT_VER:M5}
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

PLIST_SUB+=		SHORTVER=${_QT_VERSION:R} \
			FULLVER=${_QT_VERSION:C/-.*//}
.  if defined(WITH_DEBUG)
PLIST_SUB+=		DEBUG="" \
			NO_DEBUG="@comment "
.  else
PLIST_SUB+=		DEBUG="@comment " \
			NO_DEBUG=""
.  endif

# Handle additional PLIST directories, which should only be used for Qt-dist ports.
.  for dir in ETC
# Export QT_ETCDIR.
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.  endfor

.  if ${_QT_VER:M5}
.    for dir in CMAKE
# Export QT_CMAKEDIR.
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.    endfor
.  endif

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

.      if ${_QT_VER:M5}
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
.      endif

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

	# configure will run syncqt.pl if it finds a .git entry in the working directory
	touch ${WRKSRC}/.git
	# As the patch collection was created after a version bump, all module verisions
	# are tagged as 5.15.3
	touch ${WRKSRC}/.qmake.conf # easier than to -f before the sed
	${REINPLACE_CMD} -e '/MODULE_VERSION/s|5\.15\.\([0-9]*\)|${_QT_VERSION}|g' \
		${WRKSRC}/.qmake.conf

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
# If a port installs Qt version-specific binaries (e.g. "designer" which
# existed as a Qt4 application and exists as a Qt5 application and will
# probably be a Qt6 application) the port should set `QT_BINARIES=yes`.
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
# The Qt modules have an install- and deinstall-step for wrangling
# the qconfig-modules.h header, but qmake does not.
.    if ${PORTNAME} != "qmake"
post-install: qt-post-install
.    endif # PORTNAME != qmake
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

.  if ${_QT_VER:M6}
post-stage:	qt6-post-stage
# Clean-up of empty directories, as we install
# * cmake to ${LOCALBASE}/lib/cmake not ${QT_LIBDIR}/cmake.
# * pkgconfig to ${LOCALBASE}/libexec/pkgconfig not ${QT_LIBDIR}/pkgconfig
qt6-post-stage:
	${RM} -r ${STAGEDIR}${QT_LIBDIR}/cmake
	${RM} -r ${STAGEDIR}${QT_LIBDIR}/pkgconfig
.  endif

qt-create-kde-distfile:
	${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	${SH} ${PORTSDIR}/devel/${_QT_RELNAME}/files/create_kde-qt_release.sh \
		${_QT_DIST} \
		${DISTDIR}/${DIST_SUBDIR} \
		${_KDE_${_QT_DIST}_VERSION} \
		${_KDE_${_QT_DIST}_ORIGIN_TAG} \
		${_KDE_${_QT_DIST}_BRANCH}

.endif # defined(_QT_DIST_MK_INCLUDED)
