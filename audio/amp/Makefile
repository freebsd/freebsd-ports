# New ports collection makefile for:	amp
# Date created:		Jun 23 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	amp
PORTVERSION=	0.7.5
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/audio/mpeg/amp/
DISTNAME=	${PORTNAME}-${PORTVERSION}-99
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another mp3 player

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}"

MAN1=		amp.1
PLIST_FILES=	bin/amp

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
