# $FreeBSD$

PORTNAME=	libgme
PORTVERSION=	0.6.0
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/mpyne/game-music-emu/downloads/
DISTNAME=	game-music-emu-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of video game music emulators

LICENSE=	LGPL21+

USES=		cmake dos2unix ninja tar:bzip2
USE_LDCONFIG=	yes

PORTDOCS=	changes.txt design.txt gme.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s,lib/,libdata/,' \
		${WRKSRC}/gme/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
