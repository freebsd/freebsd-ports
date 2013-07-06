# $FreeBSD$
#
# Provide support to use the legacy FreeBSD make
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:		fmake
# Usage:		USES=fmake
#

.if !defined(_INCLUDE_USES_FMAKE_MK)
_INCLUDE_USES_FMAKE_MK=	yes

.if defined(fmake_ARGS)
IGNORE=	Incorrect 'USES+= fmake:${fmake_ARGS}' fmake takes no arguments
.endif

.if defined(.PARSEDIR)
FMAKE=			${LOCALBASE}/bin/fmake
BUILD_DEPENDS+=		${FMAKE}:${PORTSDIR}/devel/fmake
CONFIGURE_ENV+=		MAKE=${FMAKE}

.if !target(do-build)
do-build:
	@set -e ; (cd ${BUILD_WRKSRC}; if ! ${SETENV} ${MAKE_ENV} ${FMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
		if [ -n "${BUILD_FAIL_MESSAGE}" ] ; then \
			${ECHO_MSG} "===> Compilation failed unexpectedly."; \
			(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") | ${FMT} 75 79 ; \
		fi; \
		${FALSE}; \
	fi)
.endif

.if !target(do-install)
do-install:
	@set -e ; (cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${FMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif
.endif
.endif
