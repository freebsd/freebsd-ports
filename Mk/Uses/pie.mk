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

CFLAGS+=	-fPIE -fPIC
CXXFLAGS+=	-fPIE -fPIC
LDFLAGS+=	-pie

.endif
.endif
