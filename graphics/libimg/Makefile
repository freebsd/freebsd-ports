# New ports collection makefile for:	img
# Date Created:		20 February 1999
# Whom:			Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	libimg
PORTVERSION=	1.2.2
CATEGORIES=	graphics tk82
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/packages-8.0/graphics/Img/1.2/
DISTNAME=	img${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/img1.2.2

ALL_TARGET=	default

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.2 --with-tk=${PREFIX}/lib/tk8.2 \
		--disable-stubs

post-install:
	${LN} -sf ${PREFIX}/lib/Img1.2/libimg82.so.1 ${PREFIX}/lib/libimg.so.1
	${LN} -sf ${PREFIX}/lib/libimg.so.1 ${PREFIX}/lib/libimg.so

.include <bsd.port.mk>
