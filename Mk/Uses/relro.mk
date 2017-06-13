# $FreeBSD$
#
# Compile a port with RELRO flags
#
# Feature:      relro
# Usage:        USES=relro
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_RELRO_MK)
_INCLUDE_USES_RELRO_MK=    yes

.if !empty(relro_ARGS)
IGNORE=		USES=relro does not require args
.endif

LDFLAGS+=	-Wl,-z,relro -Wl,-z,now

.endif
