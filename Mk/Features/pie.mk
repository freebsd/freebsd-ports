# PIE Support
#
# Produce a Position-Independent Executable (PIE) instead of a "normal"
# fixed-address ELF.
# A PIE is an executable whose code sections are compiled and linked so that,
# at runtime, they can be loaded at any base address in memory.
#
# Because it can be loaded at unpredictable addresses, PIE enables full Address
# Space Layout Randomization (ASLR) for your main executable-making certain
# classes of memory-corruption exploits much harder.

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

