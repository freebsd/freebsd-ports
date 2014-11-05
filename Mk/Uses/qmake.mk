# $FreeBSD$
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
#
#
# Variables for ports:
# QMAKE_ENV		- Environment passed to qmake.
#			Default: ${CONFIGURE_ENV}
# QMAKE_ARGS		- Arguments passed to qmake.
#			Default: see below
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

# _QT_VERSION is defined in bsd.qt.mk, only if a correct Qt version was selected
# via USE_QT*.
.if empty(_QT_VERSION)
IGNORE=	'USES+= qmake' must be accompanied with 'USE_QT[${_QT_SUPPORTED:S/ //g}]= #'
.endif

# _env is a private argument used only by bsd.qt.mk to get variables and custom
# targets (currently, only qmake-configure), without qmake being added to the
# configure stage.
_VALID_ARGS=	norecursive outsource _env

.for arg in ${qmake_ARGS}
.  if empty(_VALID_ARGS:M${arg})
IGNORE=	Incorrect 'USES+= qmake' usage: argument '${arg}' is not recognized
.  endif
.endfor

.if ! ${qmake_ARGS:M_env}
USE_QT${_QT_VERSION:R:R}+=	qmake_build
.endif

.if ${_QT_VERSION:M5*}
# We deliberately do not pass -I${LOCALBASE}/include and -L${LOCALBASE}/lib
# in the FreeBSD mkspecs because in Qt5 they are always added before the
# paths in ${WRKSRC}. In other words, if one is upgrading an existing
# installation the old headers and libraries will always be picked up.
# Those directories to be passed though, they just need to be passed last.
# See QTBUG-40825 and ports/194088 for more information.
CONFIGURE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib
.endif  # ${_QT_VERSION:M5*}

# QMAKESPEC belongs to bsd.qt.mk.
QMAKE_ENV?=	${CONFIGURE_ENV}
QMAKE_ARGS+=	-spec ${QMAKESPEC} \
		QMAKE_CC="${CC}" QMAKE_CXX="${CXX}" \
		QMAKE_LINK_C="${CC}" QMAKE_LINK_C_SHLIB="${CC}" \
		QMAKE_LINK="${CXX}" QMAKE_LINK_SHLIB="${CXX}" \
		QMAKE_CFLAGS="${CFLAGS}" \
		QMAKE_CXXFLAGS="${CXXFLAGS}" \
		QMAKE_LFLAGS="${LDFLAGS}" \
		QMAKE_CFLAGS_DEBUG="" \
		QMAKE_CFLAGS_RELEASE="" \
		QMAKE_CXXFLAGS_DEBUG="" \
		QMAKE_CXXFLAGS_RELEASE="" \
		PREFIX="${PREFIX}"

.if defined(WITH_DEBUG)
QMAKE_ARGS+=	CONFIG+="debug" \
		CONFIG-="release"
.else
QMAKE_ARGS+=	CONFIG+="release" \
		CONFIG-="debug separate_debug_info"
.endif # defined(WITH_DEBUG)

# We set -recursive by default to keep qmake from running in the build stage.
.if ! ${qmake_ARGS:Mnorecursive}
QMAKE_ARGS+=	-recursive
.endif

.if defined(QMAKE_VERBOSE)
QMAKE_ARGS+=	-d
.endif

# _QMAKE_WRKSRC (and _QMAKE, below) are needed to abstract the qmake target and
# use it for both qtbase and USES=qmake ports. They are private, not supposed to
# be used anywhere else.
_QMAKE_WRKSRC?=	${CONFIGURE_WRKSRC}
.if ${qmake_ARGS:Moutsource}
CONFIGURE_WRKSRC=	${WRKDIR}/.build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}
QMAKE_SOURCE_PATH?=	${WRKSRC}
.else
QMAKE_SOURCE_PATH?=	# empty
.endif

.if ! ${qmake_ARGS:M_env}
DESTDIRNAME=	INSTALL_ROOT
.endif

# Define a custom target to make it usable by bsd.qt.mk for internal Qt
# configuration.
qmake-configure:
	@${MKDIR} ${_QMAKE_WRKSRC}
	@cd ${_QMAKE_WRKSRC} && \
		${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${QMAKE_SOURCE_PATH}

.if !target(do-configure) && ! ${qmake_ARGS:M_env}
do-configure: qmake-configure
	@${DO_NADA}
.endif

.endif # !defined(_INCLUDE_USES_QMAKE_MK)
