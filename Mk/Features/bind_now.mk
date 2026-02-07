# BIND_NOW Support
#
# When generating an executable or shared library, mark it to tell the dynamic
# linker to resolve all symbols when the program is started, or when the shared
# library is loaded by dlopen, instead of deferring function call resolution to
# the point when the function is first called.

.if !defined(_BIND_NOW_MK_INCLUDED)
_BIND_NOW_MK_INCLUDED=	yes
BIND_NOW_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(BIND_NOW_UNSAFE)
LDFLAGS+=	-Wl,-znow
.  endif
.endif
