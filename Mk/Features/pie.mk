# PIE Support

.if !defined(_PIE_MK_INCLUDED)
_PIE_MK_INCLUDED=	yes
PIE_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(PIE_UNSAFE)
.    if defined(_INCLUDE_USES_CMAKE_MK)
CMAKE_ARGS+=	-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
.    else
PIE_CFLAGS?=	-fPIE -fPIC
CFLAGS+=	${PIE_CFLAGS}
CXXFLAGS+=	${PIE_CFLAGS}
LDFLAGS+=	-pie
STATIC_PIE_ARGS+=	-static-pie
.    endif
.  endif
.endif

