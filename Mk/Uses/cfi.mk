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

.if ${cfi_ARGS:Mconfigure}
CONFIGURE_ARGS+=	--enable-cfi
.else

CFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
CXXFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
LDFLAGS+=	-fsanitize=cfi -fvisibility=hidden -flto
.endif

.endif
