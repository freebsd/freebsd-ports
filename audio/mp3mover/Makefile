# ex:ts=8
# New ports collection makefile for:	mp3mover
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mp3mover
PORTVERSION=	1.2
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.doc.ic.ac.uk/~jsm00/scripts/

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MP3/Tag.pm:${PORTSDIR}/audio/p5-tagged

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3mover.pl ${PREFIX}/bin/mp3mover
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${CP} ${WRKSRC}/sample-.mp3moverrc ${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
