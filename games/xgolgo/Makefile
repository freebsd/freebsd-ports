# New ports collection makefile for:   xgolgo
# Date created:        1 July 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xgolgo
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	#
DISTNAME=	xeyes-g

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Watches what you are doing and whether you're hostile or not

DEPRECATED=	mastersite disappeared, no longer maintained by author
EXPIRATION_DATE=2006-02-15

WRKSRC=		${WRKDIR}/xeyes
USE_IMAKE=	yes
MAN1=		xgolgo.1
PLIST_FILES=	bin/xgolgo

post-patch:
	@${CP} ${WRKSRC}/xeyes.man ${WRKSRC}/xgolgo.man

.include <bsd.port.mk>
