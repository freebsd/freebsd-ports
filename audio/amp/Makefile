# New ports collection makefile for:	amp
# Date created:		Jun 23 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	amp
PORTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	audio
#MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
# the author's site seems dead.
MASTER_SITES=	ftp://ftp.clara.net/pub/unix/Audio/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Another mp3 player

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		amp.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
