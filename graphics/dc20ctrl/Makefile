# New ports collection makefile for:	dc20ctrl
# Date created:		17 Feb 1998
# Whom:			Ugo Paternostro <paterno@dsi.unifi.it>
#
# $FreeBSD$
#

PORTNAME=	dc20ctrl
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.paternostro.org/~ugo/binaries/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital camera control and download tool for Kodak DC20 camera

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png

MAKE_ARGS=	-DUSE_JPEG -DUSE_TIFF -DUSE_PNG

MAN1=		dc20ctrl.1
PLIST_FILES=	bin/dc20ctrl

do-install:
	${INSTALL_PROGRAM} -g dialer -m 02755 ${WRKSRC}/dc20ctrl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dc20ctrl.man ${MANPREFIX}/man/man1/dc20ctrl.1

.include <bsd.port.mk>
