PORTNAME=	libgme
DISTVERSION=	0.6.3-183
DISTVERSIONSUFFIX=	-g05a2aa2
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of video game music emulators
WWW=		https://github.com/libgme/game-music-emu

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++11-lang dos2unix pathfix
DOS2UNIX_FILES=	${PORTDOCS}
USE_GITHUB=	yes
GH_PROJECT=	game-music-emu
USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_UBSAN

PORTDOCS=	changes.txt design.txt gme.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
