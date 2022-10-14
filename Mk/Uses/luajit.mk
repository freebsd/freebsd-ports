# Select your favorite luajit runtime
# Feature:    luajit
# Usage:      USES=  luajit[:version]
# MAINTAINER: adamw@FreeBSD.org

.if !defined(_INCLUDE_USES_LUAJIT_MK)
_INCLUDE_USES_LUAJIT_MK=yes

.if !empty(luajit_ARGS)
LUAJIT_VER=	${luajit_ARGS}
.else
LUAJIT_VER=	${LUAJIT_DEFAULT}
.endif

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync
VALID_LUAJIT_VER=	luajit luajit-devel luajit-openresty

.if empty(VALID_LUAJIT_VER:M${LUAJIT_DEFAULT})
IGNORE=	Invalid luajit default version ${LUAJIT_DEFAULT}: valid versions are ${VALID_LUAJIT_VER}
.elif empty(VALID_LUAJIT_VER:M${LUAJIT_VER})
IGNORE=	Invalid luajit version ${LUAJIT_VER}: valid versions are ${VALID_LUAJIT_VER}
.endif

LIB_DEPENDS+=	libluajit-5.1.so:lang/${LUAJIT_VER}

.endif
