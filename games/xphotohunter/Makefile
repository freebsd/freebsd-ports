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

MAINTAINER=	clive@CirX.ORG

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
