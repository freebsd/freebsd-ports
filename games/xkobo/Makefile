# New ports collection makefile for:    xkobo
# Date created:		18 Jul 1995
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	xkobo
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://ftp.uoknor.edu/mirrors/X/contrib/games/
MASTER_SITE_SUBDIR=	games

MAINTAINER=	will@FreeBSD.org
COMMENT=	Multi-way scrolling shoot 'em up game for X.  Strangely addictive

USE_IMAKE=	yes
USE_XORG=	x11 xext
ALL_TARGET=	xkobo
MAN1=		xkobo.1

post-configure:
	${REINPLACE_CMD} -E -e 's,^.* CC = .*$$, CC=${CC},' \
			    -e 's,^.* CXX = .*$$, CXX=${CXX},' ${WRKSRC}/Makefile

post-install:
	${CHMOD} u-s,g+s ${PREFIX}/bin/xkobo
	${CHOWN} root:games ${PREFIX}/bin/xkobo ${PREFIX}/lib/X11/xkobo-scores
	${CHMOD} 775 ${PREFIX}/lib/X11/xkobo-scores

.include <bsd.port.mk>
