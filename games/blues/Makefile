PORTNAME=	blues
PORTVERSION=	g20220312
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Blues Brothers, Jukebox Adventure, and Prehistorik 2 engine reimplementation
WWW=		https://github.com/cyxx/blues

LIB_DEPENDS=	libmodplug.so:audio/libmodplug

USES=		gmake sdl
USE_SDL=	sdl2
USE_GITHUB=	yes
GH_ACCOUNT=	cyxx
GH_TAGNAME=	d4b94bb

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
