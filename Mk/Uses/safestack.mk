# $FreeBSD$
#
# Compile a port with SafeStack
#
# Feature:	safestack
# Usage:	USES=safestack or USES=safestack:args
# Valid ARGS:	configure
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_SAFESTACK_MK)
_INCLUDE_USES_SAFESTACK_MK=    yes

.if ${safestack_ARGS:Mconfigure}
CONFIGURE_ARGS+=	--enable-safestack
.else
CFLAGS+=		-fsanitize=safe-stack
CXXFLAGS+=		-fsanitize=safe-stack
LDFLAGS+=		-fsanitize=safe-stack
.endif

.endif
