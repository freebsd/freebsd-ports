# New ports collection makefile for:	xisola
# Date created:				9 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xisola
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple board game for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
