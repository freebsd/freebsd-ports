# Sanitize Support
#
# Variables that can be used:
#
# WITH_SANITIZE		Enable for all ports.
# 			Sanitizer exits for each bug detected, so it is not
# 			advisable to enable it globally.
# WITH_SANITIZE_PORTS	Enable for specified category/port-name
# SANITIZE_FLAGS	Comma-separated list of sanitizers to be enabled
# 			Default: address
#

.if !defined(_SANITIZE_MK_INCLUDED)
_SANITIZE_MK_INCLUDED=	yes
SANITIZE_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(SANITIZE_UNSAFE)
     SANITIZE_FLAGS?=	address
.    if defined(_INCLUDE_USES_MESON_MK)
       MESON_ARGS+= -Db_sanitize=${SANITIZE_FLAGS}
.    elif defined(_INCLUDE_USES_QMAKE_MK) || defined(_QT_DIST_MK_INCLUDED)
       QMAKE_ARGS+=	QMAKE_LFLAGS_NOUNDEF=
       QMAKE_ARGS+=	CONFIG+=sanitize
.      for f in ${SANITIZE_FLAGS}
       QMAKE_ARGS+=	CONFIG+=sanitize_${f}
.      endfor
.    else
       CFLAGS+=		-fsanitize=${SANITIZE_FLAGS}
       CXXFLAGS+=	-fsanitize=${SANITIZE_FLAGS}
       LDFLAGS+=	-fsanitize=${SANITIZE_FLAGS}
.    endif
.  endif
.endif
