# LTO Support
#
# This file enforces Link Time Optimization for ports.
# In order to use it, add WITH_LTO=yes to your /etc/make.conf.

.if !defined(_LTO_MK_INCLUDED)
_LTO_MK_INCLUDED=	yes
LTO_Include_MAINTAINER=	pkubaj@FreeBSD.org

.  if !defined(LTO_UNSAFE)
# Overridable as a user may want to use -flto
LTO_FLAGS?=	-flto=thin
CFLAGS+=	${LTO_FLAGS}
CXXFLAGS+=	${LTO_FLAGS}
LDFLAGS+=	${LTO_FLAGS}
.  endif
.endif
