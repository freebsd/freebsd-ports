# $FreeBSD$
#
# Compile a port with PIE flags
#
# Feature:	pie
# Usage:	USES=pie or USES=pie:args
# Valid ARGS:	configure, default
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_PIE_MK)
_INCLUDE_USES_PIE_MK=    yes

.if ${pie_ARGS:Mconfigure}
CONFIGURE_ARGS+=	--enable-pie
.else
CFLAGS+=		-fPIE -fPIC
CXXFLAGS+=		-fPIE -fPIC
LDFLAGS+=		-pie
.endif

.endif
