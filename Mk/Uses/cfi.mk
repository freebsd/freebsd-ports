# $FreeBSD$
#
# Compile a port with CFI
#
# Feature:      cfi
# Usage:        USES=cfi
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_CFI_MK)
_INCLUDE_USES_CFI_MK=    yes
.if ${OSVERSION} >= 1200020 && ${LLD_IS_LD} == "yes"
.if ${ARCH} == "amd64"

CFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
CXXFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
LDFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto

.endif
.endif
.endif
