# New ports collection makefile for:	img
# Version required:	1.1
# Date Created:		20 February 1999
# Whom:			Glenn Johnson
#
# $FreeBSD$
#

DISTNAME=	img1.1.4
PKGNAME=	libimg-1.1.4
CATEGORIES=	graphics tk80
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/packages-8.0/graphics/Img/1.1.4/

MAINTAINER=	gljohns@bellsouth.net

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80 \
		png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/img1.1

ALL_TARGET=	default
INSTALL_TARGET=	install-base

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.0 --with-tk=${PREFIX}/lib/tk8.0

post-install:
	${LN} -sf ${PREFIX}/lib/Img1.1/libimg1.1.so.1 ${PREFIX}/lib/libimg.so.1
	${LN} -sf ${PREFIX}/lib/libimg.so.1 ${PREFIX}/lib/libimg.so

.include <bsd.port.mk>
