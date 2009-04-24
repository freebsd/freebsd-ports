# New ports collection Makefile for:	freebsd-carddeck-kde4
# Date created:				2009-02-02
# Whom:					swhetzel@gmail.com
#
# $FreeBSD$

PORTNAME=	freebsd-carddeck
PORTVERSION=	1.0
CATEGORIES=	games kde
MASTER_SITES=	# empty
PKGNAMEPREFIX=	kde4-
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	swhetzel@gmail.com
COMMENT=	FreeBSD themed deck for KDE card games

USE_KDE4=	kdehier kdeprefix

NO_BUILD=	yes

DECKSDIR=	${PREFIX}/share/apps/carddecks/decks/

do-install:
	${MKDIR} ${DECKSDIR}
	${INSTALL_DATA} ${FILESDIR}/deck_freebsd.desktop ${DECKSDIR}
	${INSTALL_DATA} ${FILESDIR}/deck_freebsd.png ${DECKSDIR}

.include <bsd.port.mk>
