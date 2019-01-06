# Created by: Sir l33tname <sirl33tname@gmail.com>
# $FreeBSD$

PORTNAME=	lua51
PORTVERSION=	0.4.6
DISTVERSIONPREFIX=v
CATEGORIES=	devel
PKGNAMESUFFIX=	-libevent

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Lua libevent binding

LICENSE=	MIT

LIB_DEPENDS=	libevent.so:devel/libevent
RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:net/luasocket-51

USES=		gmake pkgconfig lua:51

USE_GITHUB=	yes
GH_ACCOUNT=	harningt
GH_PROJECT=	luaevent

MAKE_ENV+=	INSTALL_DIR_LUA=${LUA_MODSHAREDIR}
MAKE_ENV+=	INSTALL_DIR_BIN=${LUA_MODLIBDIR}

CFLAGS+=	`pkgconf --cflags lua-${LUA_VER}` \
		`pkgconf --cflags libevent` \
		-I${LUA_INCDIR}
LDFLAGS+=	-shared -L${LOCALBASE}/lib \
		`pkgconf --libs lua-${LUA_VER}` \
		`pkgconf --libs libevent`

PLIST_FILES=	${LUA_MODLIBDIR}/luaevent/core.so \
		${LUA_MODSHAREDIR}/luaevent.lua

post-patch:
		@${REINPLACE_CMD} -e 's/CFLAGS[[:blank:]]*=/CFLAGS\+=/g' ${WRKSRC}/Makefile
		@${REINPLACE_CMD} -e 's/LDFLAGS[[:blank:]]*=/LDFLAGS\+=/g' ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
