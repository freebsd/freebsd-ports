# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp3mover
PORTVERSION=	2.1.1
CATEGORIES=	audio perl5
MASTER_SITES=	SF/mediamover/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename mp3s and manipulate them

RUN_DEPENDS=	p5-tagged>=0:${PORTSDIR}/audio/p5-tagged

USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/mp3mover
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3mover.pl ${STAGEDIR}${PREFIX}/bin/mp3mover
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample-.mp3moverrc ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/shellperfect-.mp3moverrc ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
