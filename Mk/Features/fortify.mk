# This enables mitigations of common memory safety issues, such as buffer
# overflows, by adding checks to functions like memcpy, strcpy, sprintf,
# and others when the compiler can determine the size of the destination
# buffer at compile time.
#
# Depends opon the FORTIFY_SOURCE implementation in the basesystem.

.if !defined(_FORTIFY_MK_INCLUDED)
_FORTIFY_MK_INCLUDED=	yes
FORTIFY_Include_MAINTAINER=	netchild@FreeBSD.org

.  if !defined(FORTIFY_UNSAFE)
FORTIFY_SOURCE?=2
FORTIFY_CFLAGS?=	-D_FORTIFY_SOURCE=${FORTIFY_SOURCE}
CFLAGS+=	${FORTIFY_CFLAGS}
CXXFLAGS+=	${FORTIFY_CFLAGS}
.  endif
.endif
