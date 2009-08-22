# ex:ts=8
# New ports collection makefile for:	mp3mover
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mp3mover
PORTVERSION=	2.1.1
CATEGORIES=	audio perl5
MASTER_SITES=	SF/mediamover/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename mp3s and manipulate them

RUN_DEPENDS=	${SITE_PERL}/MP3/Tag.pm:${PORTSDIR}/audio/p5-tagged

USE_PERL5=	yes
NO_BUILD=	yes

PORTDOCS=	readme
PLIST_FILES=	bin/mp3mover \
		%%DATADIR%%/sample-.mp3moverrc \
		%%DATADIR%%/shellperfect-.mp3moverrc
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3mover.pl ${PREFIX}/bin/mp3mover
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample-.mp3moverrc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/shellperfect-.mp3moverrc ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
