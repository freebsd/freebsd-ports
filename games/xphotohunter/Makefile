# New ports collection makefile for:	xphotohunter
# Date created:		12 Aug 1999
# Whom:			clive
#
# $FreeBSD$
#

PORTNAME=	xphotohunter
PORTVERSION=	1.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://ghs.tongi.org/ \
		http://micro.ee.nthu.edu.tw/~tomcat/Xphotohunter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game looking for the difference between two pictures

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	imlib

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
