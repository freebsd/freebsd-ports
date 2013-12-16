# Created by: ijliao
# $FreeBSD$

PORTNAME=	ximp3
PORTVERSION=	0.1.15
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players/mp3

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A simple console MP3 player

GNU_CONFIGURE=	yes
PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
