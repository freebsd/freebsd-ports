# New ports collection makefile for:	xmines
# Date created:				18 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xmines
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xmines
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmines
.endif

.include <bsd.port.mk>
