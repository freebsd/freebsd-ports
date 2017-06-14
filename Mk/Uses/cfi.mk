# $FreeBSD$
#
# Compile a port with CFI
#
# Feature:	cfi
# Usage:	USES=cfi
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_CFI_MK)
_INCLUDE_USES_CFI_MK=    yes

.if !empty(cfi_ARGS)
IGNORE=	USES=cfi does not require args
.endif

CFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
CXXFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
LDFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto

.endif
