# New ports collection makefile for:    xsok
# Date created:         07 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xsok
PORTVERSION=	1.02
CATEGORIES=	games
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A generic Sokoban game for X11

USE_IMAKE=	yes
USE_XPM=	yes
MAN6=		xsok.6

do-configure:
	cd ${WRKSRC}/src && ${XMKMF}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xsok.tex ${PREFIX}/share/doc/xsok

.include <bsd.port.mk>
