# New ports collection makefile for:	blackjack
# Date created:		23 February 1998
# Whom:			Peter Mutsaers
#
# $FreeBSD$
#

PORTNAME=	blackjack
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	One of the better implementations of blackjack, based on QT

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	3
MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
		QTDIR="${QT_PREFIX}"

MAN1=		blackjack.1
PLIST_FILES=	bin/blackjack

.include <bsd.port.mk>
