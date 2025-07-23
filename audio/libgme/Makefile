PORTNAME=	libgme
DISTVERSION=	0.6.4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/game-music-emu/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of video game music emulators
WWW=		https://github.com/libgme/game-music-emu

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++11-lang dos2unix
DOS2UNIX_FILES=	${PORTDOCS}

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_SDL2
CMAKE_OFF=	ENABLE_UBSAN GME_BUILD_STATIC

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PORTDOCS=	changes.txt design.txt gme.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
