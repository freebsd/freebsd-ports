# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xbat
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	xev111

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	XEVIOUS like shooting game

NO_CDROM=	Possible copyright infringement

USES=		imake
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/Xev111
ALL_TARGET=	xbat

post-install:
	${CHOWN} root:games ${PREFIX}/bin/xbat
	${CHMOD} 2755 ${PREFIX}/bin/xbat
	${CHOWN} -R root:games ${PREFIX}/lib/X11/Xbat/Score/
	${CHMOD} 664 ${PREFIX}/lib/X11/Xbat/Score/*
	${CHMOD} 755 ${PREFIX}/lib/X11/Xbat/Score/

.include <bsd.port.mk>
