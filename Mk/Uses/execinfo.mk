# $FreeBSD$
#
# handle dependency on libexecinfo
#
# Feature:	execinfo
# Usage:	USES=execinfo
#
# Takes no arguments
#
# Exported variables:
#
# EXECINFO_CPPFLAGS - preprocessor flags needed to correctly use
#                     execinfo library
# EXECINFO_LDFLAGS  - linker flags needed to correctly use
#                     execinfo library
#

.if !defined(_INCLUDE_USES_EXECINFO_MK)
_INCLUDE_USES_EXECINFO_MK=	yes

.if !exists(/usr/lib/libexecinfo.so)
LIB_DEPENDS+=	libexecinfo.so:devel/libexecinfo
EXECINFO_CPPFLAGS=	-I${LOCALBASE}/include
EXECINFO_LDFLAGS=	-L${LOCALBASE}/lib
.endif

.endif
