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

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
