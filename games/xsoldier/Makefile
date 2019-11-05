# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xsoldier
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.interq.or.jp/libra/oohara/xsoldier/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Space-based shoot-em up game for X11

USES=		xorg
USE_XORG=	x11 ice sm xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
MAKE_ARGS=	CC_OPTIMIZE="${CFLAGS}"

SCOREFILE=	/var/games/xsoldier.scores
PLIST_SUB=	SCOREFILE=${SCOREFILE}

.include <bsd.port.mk>
