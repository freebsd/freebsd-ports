# New ports collection makefile for:	yahtzee
# Date created:		Friday 4th July, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	yahtzee
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}-src
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses version of the dice game for one or more players

WRKSRC=		${WRKDIR}/${PORTNAME}

# Distribution does not include an install target. So here it is.
#
do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/yahtzee ${PREFIX}/bin
	${MKDIR} -m 0755 ${DATADIR}
	${INSTALL_DATA} -m 0664 -o root -g games /dev/null ${DATADIR}/yahtzee.sco

.include <bsd.port.mk>
