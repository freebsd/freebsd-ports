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
MASTER_SITES=	http://www.doc.ic.ac.uk/~jsm00/scripts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename mp3s and manipulate them

RUN_DEPENDS=	${SITE_PERL}/MP3/Tag.pm:${PORTSDIR}/audio/p5-tagged

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3mover.pl ${PREFIX}/bin/mp3mover
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/sample-.mp3moverrc ${DATADIR}
	${CP} ${WRKSRC}/shellperfect-.mp3moverrc ${DATADIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
