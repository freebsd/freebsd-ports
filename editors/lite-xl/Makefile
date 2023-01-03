PORTNAME=	lite-xl
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight text editor written mostly in Lua
WWW=		https://lite-xl.com/

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2

USES=		lua:54 meson pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-colors:colors ${PORTNAME}-plugins:plugins
GH_TAGNAME=	b3a9cdd:colors b1eb39c:plugins

OPTIONS_DEFINE=	DOCS

PORTDOCS=	changelog.md licenses.md

post-install:
	${CP} -a ${WRKSRC_colors}/colors ${STAGEDIR}${DATADIR}
	${MV} ${WRKSRC_plugins}/plugins/language_*.lua \
		${STAGEDIR}${DATADIR}/plugins
	${CP} -a ${WRKSRC_plugins}/plugins \
		${STAGEDIR}${DATADIR}/plugins/extra

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/changelog.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
