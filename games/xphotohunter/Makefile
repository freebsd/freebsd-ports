# New ports collection makefile for:	xphotohunter
# Date created:		12 Aug 1999
# Whom:			clive
#
# $FreeBSD$
#

PORTNAME=	xphotohunter
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://www.oz.nthu.edu.tw/~u860905/Xphotohunter/

MAINTAINER=	clive@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
