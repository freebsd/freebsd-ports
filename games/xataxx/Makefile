# New ports collection makefile for:	xataxx
# Date created:				4 July 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xataxx
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strategy game of position and movement for X Window System

USE_IMAKE=	yes
MAN6=		xataxx.6

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xataxx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xataxx
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/xataxx
.endif

.include <bsd.port.mk>
