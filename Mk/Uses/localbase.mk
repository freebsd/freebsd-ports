# $FreeBSD$
#
# handle enforcing localbase in path
#
# Feature:	localbase
# Usage:	USES=localbase or USES=localbase:args
# Valid ARGS:	ldflags		Set LDFLAGS instead of LIBS
#
# MAINTAINER:	portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_LOCALBASE_MK)
_INCLUDE_USES_LOCALBASE_MK=	yes
_USES_POST+=	localbase
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LOCALBASE_POST_MK)
_INCLUDE_USES_LOCALBASE_POST_MK=yes

CPPFLAGS+=	-isystem ${LOCALBASE}/include
CFLAGS+=	-isystem ${LOCALBASE}/include
CXXFLAGS+=	-isystem ${LOCALBASE}/include
.if ${localbase_ARGS:Mldflags}
LDFLAGS+=	-L${LOCALBASE}/lib
.else
LIBS+=		-L${LOCALBASE}/lib
.endif

# Use CONFIGURE_ENV instead of CMAKE_ARGS because devel/cmake itself also needs
# this, and CMAKE_ARGS is not used when bootstrapping CMake.
CONFIGURE_ENV+=	CMAKE_PREFIX_PATH="${LOCALBASE}"
.endif
