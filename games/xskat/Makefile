# New ports collection makefile for:	xskat
# Date created:		27 Apr 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xskat
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.xskat.de/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Skat

.if defined(WITH_ALTENBURGER_CARDS)
DISTFILES+=	xskat-cards.tar.gz
RESTRICTED=	"The altenburger card file is NOT freely redistributable!"
.endif

USE_IMAKE=	yes
USE_XORG=	x11
MAN1=		xskat.1 xskat-de.1
PLIST_FILES=	bin/xskat

pre-fetch:
.if !defined(WITH_ALTENBURGER_CARDS)
	@${ECHO}
	@${ECHO} "You can compile xskat with the beautiful original"
	@${ECHO} "Altenburger card set by setting WITH_ALTENBURGER_CARDS"
	@${ECHO}
.endif

post-patch:
.if defined(WITH_ALTENBURGER_CARDS)
	cd ${WRKSRC}; ${CP} ../xskat-cards.c cards.c
.endif

.include <bsd.port.mk>
