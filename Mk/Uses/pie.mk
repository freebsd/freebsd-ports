# $FreeBSD$
#
# Compile a port with PIE flags
#
# Feature:      pie
# Usage:        USES=pie
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if ${OSVERSION} > 1100000
.if !defined(_INCLUDE_USES_PIE_MK)
_INCLUDE_USES_PIE_MK=    yes

.if !empty(pie_ARGS)
IGNORE=			USES=pie does not require args
.endif

.if ${PIE_ARGS:Mconfigure}
CONFIGURE_ARGS+=	--enable-pie
.else
CFLAGS+=		-fPIC -fPIE
CXXFLAGS+=		-fPIC -fPIE
LDFLAGS+=		-pie
.endif

.endif
.endif
