# Created by: jmz
# $FreeBSD$

PORTNAME=	jetpack
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arcade action game for X11

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

USE_IMAKE=	yes
USE_XORG=	x11 xext
MAKE_FLAGS=	PREFIX=${PREFIX} -f
MAN6=		jetpack.6

post-install:
	@${CHOWN} root:games ${PREFIX}/bin/jetpack
	@${CHMOD} g+s,u-s ${PREFIX}/bin/jetpack
	@${CHOWN} root:games ${PREFIX}/lib/X11/jetpack
	@${CHMOD} g+w  ${PREFIX}/lib/X11/jetpack
	@${CHMOD} go+r ${PREFIX}/lib/X11/jetpack/jetpack.lev000

.include <bsd.port.mk>
