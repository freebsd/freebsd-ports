# Created by: Sir l33tname <sirl33tname@gmail.com>
# $FreeBSD$

PORTNAME=	libevent
PORTVERSION=	0.4.6
DISTVERSIONPREFIX=v
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Lua libevent binding

LICENSE=	MIT

LIB_DEPENDS=	libevent.so:devel/libevent
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/socket/core.so:net/luasocket@${LUA_FLAVOR}

USES=		gmake pkgconfig lua:module

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
