include $(EST)/config/systems/default.mak

## echo -n doesn't work (well only sometimes ?)
ECHO_N = /usr/bin/printf "%s"

NAWK=awk

NAS_LIB=$(PKG_X11BASE)/lib
NAS_INCLUDE=$(PKG_X11BASE)/include

X11_LIB=$(PKG_X11BASE)/lib
X11_INCLUDE=$(PKG_X11BASE)/include

OS_INCLUDES+=-I$(PKG_PREFIX)/include
OS_LIBS+=-L$(PKG_PREFIX)/lib
