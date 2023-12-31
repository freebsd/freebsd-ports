PORTNAME=	lite-xl
PORTVERSION=	2.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight text editor written mostly in Lua
WWW=		https://lite-xl.com/

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2

USES=		desktop-file-utils lua:54 meson pkgconfig sdl
USE_SDL=	sdl2
MESON_ARGS=	-Duse_system_lua=true

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-colors:colors ${PORTNAME}-plugins:plugins
GH_TAGNAME=	315f123:colors 433d368:plugins

OPTIONS_DEFINE=	DOCS

PORTDOCS=	changelog.md licenses.md

post-install:
	${CP} -a ${WRKSRC_colors}/colors ${STAGEDIR}${DATADIR}
	${MV} ${WRKSRC_plugins}/plugins/language_*.lua \
		${STAGEDIR}${DATADIR}/plugins
	${CP} -a ${WRKSRC_plugins}/plugins \
		${STAGEDIR}${DATADIR}/plugins/extra
	${CP} -a ${WRKSRC}/resources/linux/org.lite_xl.lite_xl.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${CP} -a ${WRKSRC}/resources/linux/org.lite_xl.lite_xl.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	${CP} -a ${WRKSRC}/resources/icons/lite-xl.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/changelog.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
