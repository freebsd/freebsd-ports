# $FreeBSD$
#
# Compile a port with SafeStack
#
# Feature:      safestack
# Usage:        USES=safestack
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_SAFESTACK_MK)
_INCLUDE_USES_SAFESTACK_MK=    yes
.if ${OSVERSION} >= 1100508
.if ${ARCH} == "amd64"

CFLAGS+=	-fsanitize=safe-stack
CXXFLAGS+=	-fsanitize=safe-stack
LDFLAGS+=	-fsanitize=safe-stack

.endif
.endif
.endif
