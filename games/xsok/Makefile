# New ports collection makefile for:    xsok
# Date created:         07 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=       xsok
PORTVERSION=	1.02
CATEGORIES=	games
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/ \
		ftp://sunsite.cnlab-switch.ch/mirror/linux/tsx-11/sources/usr.bin.X11/ \
		ftp://ftp.cdrom.com/pub/linux/tsx-11/sources/usr.bin.X11/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
MAN6=		xsok.6x

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xsok.tex ${PREFIX}/share/doc/xsok

.include <bsd.port.mk>
