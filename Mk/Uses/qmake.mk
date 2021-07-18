# There are three Qt related USES files with different access to Qt.
#   - qmake: The port requires Qt's qmake to build -- creates the configure target
#            - auto includes qt.mk
#   - qt-dist: The port is a port for a part of Qt5
#            - auto inclues qt.mk
#   - qt.mk  - Dependency handling. USE_QT=foo bar
#
#
# Provide support for qmake-based projects
#
# Feature:		qmake
# Usage:		USES=qmake or USES=qmake:ARGS
#			Must be used along with	'USE_QT*=#'
# Valid ARGS:		norecursive outsource
# ARGS description:
# norecursive		Don't pass -recursive argument to qmake binary
# outsource		Perform an out-of-source build
# no_env		Suppress modification of configure and make environment.
# no_configure		Don't add the configure target -- this is implied by 
#			HAS_CONFIGURE=yes and GNU_CONFIGURE=yes
#
#
# Variables for ports:
# QMAKE_ENV		- Environment passed to qmake.
#			Default: ${CONFIGURE_ENV}
# QMAKE_ARGS		- Arguments passed to qmake.
#			Default: see below
# QMAKE_CONFIGURE_ARGS  - Extra arguments passed to qmake after everything
#                       else, such as "-foo -no-bar". The arguments are usually
#                       set in configure.json. This variable is specific to
#                       qmake from Qt 5.
#                       Default: empty
# QMAKE_SOURCE_PATH	- Path to qmake project files.
#			Default: ${WRKSRC} if out-of-source build is
#			requested, empty otherwise.
#
# User defined variables:
# QMAKE_VERBOSE		- Enable verbose configure output.
#
# MAINTAINER: kde@FreeBSD.org

.if !defined(_INCLUDE_USES_QMAKE_MK)
_INCLUDE_USES_QMAKE_MK=	yes

# Suck in qt.mk
.include "${USESDIR}/qt.mk"

_VALID_ARGS=		norecursive outsource no_env no_configure

.  for arg in ${qmake_ARGS}
.    if empty(_VALID_ARGS:M${arg})
IGNORE=			Incorrect 'USES+= qmake' usage: argument '${arg}' is not recognized
.    endif
.  endfor

# Check whether we need to add the configure target
_ADD_CONFIGURE_TARGET=	yes
.  if !empty(qmake_ARGS:Mno_configure) || defined(HAS_CONFIGURE) || defined(GNU_CONFIGURE)
_ADD_CONFIGURE_TARGET=	# unset
.  endif

# QMAKESPEC belongs to bsd.qt.mk.
QMAKE_ENV?=		${CONFIGURE_ENV}
QMAKE_ARGS+=		-spec ${QMAKESPEC} \
			QMAKE_CC="${CC}" QMAKE_CXX="${CXX}" \
			QMAKE_LINK_C="${CC}" QMAKE_LINK_C_SHLIB="${CC}" \
			QMAKE_LINK="${CXX}" QMAKE_LINK_SHLIB="${CXX}" \
			QMAKE_CFLAGS="${CFLAGS}" \
			QMAKE_CXXFLAGS="${CXXFLAGS}" \
			QMAKE_LFLAGS="${LDFLAGS}" \
			QMAKE_LIBS="${LIBS}" \
			QMAKE_CFLAGS_DEBUG="" \
			QMAKE_CFLAGS_RELEASE="" \
			QMAKE_CXXFLAGS_DEBUG="" \
			QMAKE_CXXFLAGS_RELEASE="" \
			PREFIX="${PREFIX}"

.  if defined(WITH_DEBUG)
PLIST_SUB+=		DEBUG=""
QMAKE_ARGS+=		CONFIG+="debug separate_debug_info" \
			CONFIG-="release"
.  else
PLIST_SUB+=		DEBUG="@comment "
QMAKE_ARGS+=		CONFIG+="release" \
			CONFIG-="debug separate_debug_info"
.  endif # defined(WITH_DEBUG)

# We set -recursive by default to keep qmake from running in the build stage.
.  if ! ${qmake_ARGS:Mnorecursive}
QMAKE_ARGS+=		-recursive
.  endif

.  if defined(QMAKE_VERBOSE)
QMAKE_ARGS+=		-d
.  endif

# _QMAKE_WRKSRC (and _QMAKE, below) are needed to abstract the qmake target and
# use it for both qtbase and USES=qmake ports. They are private, not supposed to
# be used anywhere else.
_QMAKE_WRKSRC?=	${CONFIGURE_WRKSRC}
.  if ${qmake_ARGS:Moutsource}
CONFIGURE_WRKSRC=	${WRKDIR}/.build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}
TEST_WRKSRC=		${BUILD_WRKSRC}
QMAKE_SOURCE_PATH?=	${WRKSRC}
.  else
QMAKE_SOURCE_PATH?=	# empty
.  endif

# Add qmake to USE_QT -- unless it's qmake itself
.  if !${PORTNAME} == qmake
USE_QT+=		qmake_build
.  endif

.  if empty(qmake_ARGS:Mno_env)
DESTDIRNAME=		INSTALL_ROOT
CONFIGURE_ENV+=		QTDIR="${QT_ARCHDIR}" QMAKE="${QMAKE}" \
			MOC="${MOC}" RCC="${RCC}" UIC="${UIC}" \
			QMAKESPEC="${QMAKESPEC}"
CONFIGURE_ARGS+=	--with-qt-includes=${QT_INCDIR} \
			--with-qt-libraries=${QT_LIBDIR} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib
.  endif

_USES_POST+=		qmake
.endif # _QMAKE_MK_INCLUDED

# =============================================================================
#
# =============================================================================

.if defined(_POSTMKINCLUDED) && !defined(_QMAKE_MK_POST_INCLUDED)
_QMAKE_MK_POST_INCLUDED=	qmake.mk

# Define a custom target to make it usable by bsd.qt.mk for internal Qt
# configuration.
qmake-configure:
	@${MKDIR} ${_QMAKE_WRKSRC}
	@cd ${_QMAKE_WRKSRC} && \
		${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} \
			${QMAKE_SOURCE_PATH} \
			${QMAKE_CONFIGURE_ARGS:?--:} ${QMAKE_CONFIGURE_ARGS}

.  if !target(do-configure) && !empty(_ADD_CONFIGURE_TARGET)
_USES_configure+=	450:qmake-configure
.  endif

.endif # !defined(_INCLUDE_USES_QMAKE_MK)
