# New ports collection makefile for:    xeyes+
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xeyes+
PORTVERSION=	2.02
CATEGORIES=	games
MASTER_SITES=	http://www.asahi-net.or.jp/~fj9y-ynym/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Horrible eyes looking at your mouse cursor

USE_X_PREFIX=	yes
USE_XPM=	yes

PLIST_FILES=	bin/xeyes+

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${X11BASE}/include -DXPM -DUSLEEP \
		-o xeyes+ xeyes+.c -L${X11BASE}/lib -lX11 -lXpm -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xeyes+ ${PREFIX}/bin

.include <bsd.port.mk>
