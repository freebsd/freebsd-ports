# New ports collection makefile for:   xgolgo
# Date created:        1 July 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xgolgo
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nemoto.ecei.tohoku.ac.jp/pub/X11/misc/
DISTNAME=	xeyes-g

MAINTAINER=	nakai@FreeBSD.org

WRKSRC=		${WRKDIR}/xeyes
USE_IMAKE=	yes
MAN1=		xgolgo.1

post-patch:
	@${CP} ${WRKSRC}/xeyes.man ${WRKSRC}/xgolgo.man

.include <bsd.port.mk>
