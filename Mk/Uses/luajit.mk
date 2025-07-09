# Select your favorite luajit runtime
# Feature:    luajit
# Usage:      USES=  luajit[:version]
# MAINTAINER: adamw@FreeBSD.org

# After bsd.port.options.mk or bsd.port.pre.mk, the following are set:
#   LUAJIT_VER:    The selected luajit version
#   LUAJIT_INCDIR: The path to luajit's header files
#   LUAJIT_LUAVER: Which luajit spec version is selected
#                  (always 2.1)

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

LUAJIT_LUAVER=	2.1

LIB_DEPENDS+=	libluajit-5.1.so:lang/${LUAJIT_VER}
LUAJIT_INCDIR=	${LOCALBASE}/include/luajit-${LUAJIT_LUAVER}

.endif
