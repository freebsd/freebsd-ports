# New ports collection makefile for:	xripple
# Date created:				6 Oct 1996
# Whom:					oly
#
# $FreeBSD$
#

PORTNAME=	xripple
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://crydee.sai.msu.ru/zeus/X11/contrib/ \
		ftp://ftp.cin.nihon-u.ac.jp/pub/X11/enlightenment/misc/ \
		ftp://ftp.dataplus.se/pub/linux/enlightenment/misc/ \
		ftp://ftp.devolution.com/pub/enlightenment/ \
		ftp://ftp.dti.ad.jp/.1/X/e/ \
		ftp://ftp.gui.uva.es/pub/linux.new/software/X11/winman/enlightenment/ \
		ftp://ftp.gwdg.de/pub/linux/tux/x/enlightenment/enlightenment/misc/ \
		ftp://ftp.pconline.com/users/gjerde/enlightenment/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X program to make bottom of screen ripple like a pool of water

PLIST_FILES=	bin/xripple
USE_IMAKE=	yes
USE_XORG=	x11 xext
ALL_TARGET=	xripple

post-configure:
	cd ${WRKSRC}; make clean

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xripple ${PREFIX}/bin

.include <bsd.port.mk>
