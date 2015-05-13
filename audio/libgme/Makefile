# $FreeBSD$

PORTNAME=	libgme
PORTVERSION=	0.6.0
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	game-music-emu
DISTNAME=	${PROJECTHOST}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of video game music emulators

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		tar:bzip2 cmake dos2unix ninja
USE_LDCONFIG=	yes

PORTDOCS=	changes.txt design.txt gme.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s,lib/,libdata/,' \
		${WRKSRC}/gme/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
