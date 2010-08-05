# New ports collection makefile for:	nettoe
# Date created:		01 July 2001
# Whom:			Christopher Preston <rbg@gayteenresource.org>
#
# $FreeBSD$
#

PORTNAME=	nettoe
PORTVERSION=	1.3.2
CATEGORIES=	games
MASTER_SITES=	SF \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	A tic-tac-toe game playable over the network

LICENSE=	GPLv2

PLIST_FILES=	bin/nettoe

MAN6=		nettoe.6

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TO-DO

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for I in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$I ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
