PORTNAME=	mpd
PORTVERSION=	0.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	audio
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	demelier.david@gmail.com
COMMENT=	Lua library for musicpd
WWW=		https://github.com/silentbicycle/lua-mpd

RUN_DEPENDS=	${LUA_REFMODLIBDIR}/socket/core.so:net/lua-luasocket@${LUA_FLAVOR}

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${LUA_DOCSDIR}

GH_ACCOUNT=	silentbicycle
GH_PROJECT=	lua-mpd

USES=		lua:51,module
USE_GITHUB=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/mpd.lua ${STAGEDIR}${LUA_MODSHAREDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/modules ${STAGEDIR}${DOCSDIR}/files
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/luadoc.css ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/files/mpd.html ${STAGEDIR}${DOCSDIR}/files
	${INSTALL_DATA} ${WRKSRC}/modules/mpd.html ${STAGEDIR}${DOCSDIR}/modules

.include <bsd.port.mk>
