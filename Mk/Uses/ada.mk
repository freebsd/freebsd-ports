# $FreeBSD$
#
# Establish Ada-capable compiler as a build dependency
#
# MAINTAINER: marino@FreeBSD.org
#
# Feature:      ada
# Usage:        USES=ada
# Valid ARGS:   does not require args

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

.if defined(ada_ARGS)
IGNORE= USES=ada does not require args
.endif

CC=		ada
BUILD_DEPENDS+=	${LOCALBASE}/gcc-aux/bin/ada:${PORTSDIR}/lang/gcc-aux

MAKE_ENV+=	PATH=${LOCALBASE}/gcc-aux/bin:${PATH}
MAKE_ENV+=	ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

CONFIGURE_ENV+=	PATH=${LOCALBASE}/gcc-aux/bin:${PATH}
CONFIGURE_ENV+=	ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

.endif
