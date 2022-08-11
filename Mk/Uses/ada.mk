# Establish Ada-capable compiler as a build dependency
# To change default compiler, define ADA_DEFAULT in make.conf
#
# Feature:      ada
# Usage:        USES=ada
# Valid ARGS:   run
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

DEPRECATED=	Depends on expired lang/gcc6-aux
EXPIRATION_DATE=2022-09-30

CC=	ada

.  if ${ada_ARGS:Mrun}
RUN_DEPENDS+=	${LOCALBASE}/gcc6-aux/bin/ada:lang/gcc6-aux
.  endif

BUILD_DEPENDS+=	${LOCALBASE}/gcc6-aux/bin/ada:lang/gcc6-aux
MAKE_ENV+=	PATH=${LOCALBASE}/gcc6-aux/bin:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat
CONFIGURE_ENV+=	PATH=${LOCALBASE}/gcc6-aux/bin:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

.endif
