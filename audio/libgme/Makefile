PORTNAME=	libgme
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/mpyne/game-music-emu/downloads/
DISTNAME=	game-music-emu-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of video game music emulators
WWW=		https://bitbucket.org/mpyne/game-music-emu

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++11-lang dos2unix tar:xz
DOS2UNIX_FILES=	${PORTDOCS}
USE_LDCONFIG=	yes

PORTDOCS=	changes.txt design.txt gme.txt readme.txt

CMAKE_OFF=	ENABLE_UBSAN

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s/lib[[:>:]]/libdata/' \
		${WRKSRC}/gme/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
