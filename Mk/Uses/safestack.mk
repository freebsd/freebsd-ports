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
.if ${OSVERSION} >= 1100122
.if ${ARCH} == "amd64"

.if !empty(safestack_ARGS)
IGNORE=			USES=safestack does not require args
.endif

.if ${SAFESTACK_ARGS:Mconfigure}
CONFIGURE_ARGS+=	--enable-safestack
.else
CFLAGS+=		-fsanitize=safe-stack
CXXFLAGS+=		-fsanitize=safe-stack
LDFLAGS+=		-fsanitize=safe-stack
.endif

.endif
.endif
.endif
