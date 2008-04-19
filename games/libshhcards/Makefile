# New ports collection makefile for:	libshhcards
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	libshhcards
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	shhcards-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for displaying game cards on X Window System

USE_XORG=	xpm
MAKEFILE=	${FILESDIR}/Makefile.lib
USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
