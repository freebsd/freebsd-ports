# Handle dependency on lang/vala
#
# Valid args:
# 	- lib:       add a lib depends
# 	- build:     add a build depends
# 	- no_depend: only used for lang/vala itself

.if ! defined(_INCLUDE_USES_VALA_MK)
_INCLUDE_USES_VALA_MK=	yes

_VALA_VERSION=		0.56.8
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
.  endif

# remove after https://gitlab.gnome.org/GNOME/vala/-/issues/1408 is fixed
CFLAGS+=	-Wno-error=incompatible-function-pointer-types

.endif
