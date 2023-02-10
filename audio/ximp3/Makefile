PORTNAME=	ximp3
PORTVERSION=	0.1.15
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players/mp3

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple console MP3 player

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATE=	Abandonware and obsolete, uses old decoder library and no ID3v2 support
EXPIRATION_DATE=2023-03-09

GNU_CONFIGURE=	yes
PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
