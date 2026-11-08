# Provide support for Vinyl-Cache
#
# Feature:      vinyl
# Usage:        USES=vinyl
# Valid ARGS:   09, run
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_VINYL_MK)
_INCLUDE_USES_VINYL_MK=    yes

VINYL_VERSION=	${VINYL_DEFAULT}

.  if ${vinyl_ARGS:M09}
VINYL_VERSION=	09
.  elif defined(VINYL_DEFAULT)
.  endif

RUN_DEPENDS+=	vinyl${VINYL_VERSION}>=${VINYL_VERSION}:www/vinyl${VINYL_VERSION}
BUILD_DEPENDS+=	vinyl${VINYL_VERSION}>=${VINYL_VERSION}:www/vinyl${VINYL_VERSION}

CFLAGS+= 	-I${LOCALBASE}/include -I${LOCALBASE}/include/vinyl-cache
CPPFLAGS+= 	-I${LOCALBASE}/include -I${LOCALBASE}/include/vinyl-cache
LIBS+=		-L${LOCALBASE}/lib

.endif
