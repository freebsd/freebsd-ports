# DEBUG Support
#
# Add WITH_DEBUG into make.conf:
# - If set, debugging flags are added to CFLAGS and the binaries don't get
#   stripped by INSTALL_PROGRAM or INSTALL_LIB. Besides, individual ports might
#   add their specific to produce binaries for debugging purposes. You can
#   override the debug flags that are passed to the compiler by setting
#   DEBUG_FLAGS. It is set to "-g" at default.

.if !defined(_DEBUG_MK_INCLUDED)
_DEBUG_MK_INCLUDED=	yes
DEBUG_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(INSTALL_STRIPPED)
STRIP=	#none
MAKE_ENV+=	DONTSTRIP=yes
STRIP_CMD=	${TRUE}
.  endif
DEBUG_FLAGS?=	-g
CFLAGS:=		${CFLAGS:N-O*:N-fno-strict*} ${DEBUG_FLAGS}
.  if defined(INSTALL_TARGET)
INSTALL_TARGET:=	${INSTALL_TARGET:S/^install-strip$/install/g}
.  endif
.endif
