include $(EST)/config/systems/default.mak

## echo -n doesn't work (well only sometimes ?)
ECHO_N = /usr/bin/printf "%s"

NAWK=awk

NAS_LIB=$(PKG_LOCALBASE)/lib
NAS_INCLUDE=$(PKG_LOCALBASE)/include

X11_LIB=$(PKG_LOCALBASE)/lib
X11_INCLUDE=$(PKG_LOCALBASE)/include

OS_INCLUDES+=-I$(PKG_PREFIX)/include
OS_LIBS+=-L$(PKG_PREFIX)/lib
