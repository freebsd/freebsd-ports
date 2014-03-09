# $FreeBSD$
#
# Establish Ada-capable compiler as a build dependency
#
# MAINTAINER: marino@FreeBSD.org
#
# Feature:      ada
# Usage:        USES=ada
# Valid ARGS:   47

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

CC= ada

. if defined(ada_ARGS) && ${ada_ARGS} == 47
BUILD_DEPENDS+=	${LOCALBASE}/gcc47-aux/bin/ada:${PORTSDIR}/lang/gcc47-aux
MAKE_ENV+=	PATH=${LOCALBASE}/gcc47-aux/bin:${PATH}
CONFIGURE_ENV+=	PATH=${LOCALBASE}/gcc47-aux/bin:${PATH}
. else
BUILD_DEPENDS+=	${LOCALBASE}/gcc-aux/bin/ada:${PORTSDIR}/lang/gcc-aux
MAKE_ENV+=	PATH=${LOCALBASE}/gcc-aux/bin:${PATH}
CONFIGURE_ENV+=	PATH=${LOCALBASE}/gcc-aux/bin:${PATH}
. endif

MAKE_ENV+=	ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat
CONFIGURE_ENV+=	ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

.endif
