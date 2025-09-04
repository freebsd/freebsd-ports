# Handle dependency on lang/vala
#
# Valid args:
# 	- lib:		add a lib depends
# 	- build:	add a build depends
# 	- test:		add a test depends
# 	- no_depend:	only used for lang/vala itself
#
# MAINTAINER: desktop@FreeBSD.org

.if ! defined(_INCLUDE_USES_VALA_MK)
_INCLUDE_USES_VALA_MK=	yes

_VALA_VERSION=		0.56.18
_VALA_LIB_VERSION=	${_VALA_VERSION:R}
_VALA_LIBRARY=		libvala-${_VALA_LIB_VERSION}.so
_VALA_BINARY=		valac
_VALA_PORT=		lang/vala

.  if empty(vala_ARGS:Mno_depend)
.    if ! empty(vala_ARGS:Mlib)
LIB_DEPENDS+=		${_VALA_LIBRARY}:${_VALA_PORT}
.    endif
.    if ! empty(vala_ARGS:Mbuild)
BUILD_DEPENDS+=		${_VALA_BINARY}:${_VALA_PORT}
.    endif
.    if ! empty(vala_ARGS:Mtest)
TEST_DEPENDS+=		${_VALA_BINARY}:${_VALA_PORT}
.    endif
.  endif

.endif
