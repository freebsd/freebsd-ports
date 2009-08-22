# New ports collection makefile for:	nettoe
# Date created:		01 July 2001
# Whom:			Christopher Preston <rbg@gayteenresource.org>
#
# $FreeBSD$
#

PORTNAME=	nettoe
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tic-tac-toe game playable over the network

MAN6=		nettoe.6

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for I in AUTHORS BUGS COPYING ChangeLog INSTALL NEWS README TO-DO
	${INSTALL_DATA} ${WRKSRC}/$I ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
