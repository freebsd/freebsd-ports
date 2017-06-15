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

# QMAKESPEC belongs to bsd.qt.mk.
QMAKE_ENV?=	${CONFIGURE_ENV}
QMAKE_ARGS+=	-spec ${QMAKESPEC} \
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
TEST_WRKSRC=		${BUILD_WRKSRC}
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
_USES_configure+=	450:qmake-configure
.endif

.endif # !defined(_INCLUDE_USES_QMAKE_MK)
