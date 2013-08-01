# New ports collection makefile for:	xsoldier
# Date created:		22 January 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xsoldier
PORTVERSION=	1.8
CATEGORIES=	games
MASTER_SITES=	http://www.interq.or.jp/libra/oohara/xsoldier/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Space-based shoot-em up game for X11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
MAKE_ARGS=	CC_OPTIMIZE="${CFLAGS}"

USE_XORG=	x11 ice sm xpm
MAN6=		xsoldier.6

SCOREFILE=	/var/games/xsoldier.scores
PLIST_SUB=	SCOREFILE=${SCOREFILE}

post-install:
	${CHGRP} games ${PREFIX}/bin/xsoldier
	${CHMOD} g+s ${PREFIX}/bin/xsoldier
	${CP} ${EXAMPLESDIR}/xsoldier.scores ${SCOREFILE}
	${CHGRP} games ${SCOREFILE}
	${CHMOD} 664 ${SCOREFILE}

.include <bsd.port.mk>
