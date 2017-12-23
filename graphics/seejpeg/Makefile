# Created by: Donn Miller <dmmiller@cvzoom.net>
# $FreeBSD$

PORTNAME=	seejpeg
PORTVERSION=	1.10
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/viewers/svga

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console graphics viewer using the svga console graphics library

LIB_DEPENDS=	libvga.so:graphics/svgalib

USES=		gmake jpeg tar:tgz
ALL_TARGET=	seejpeg
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/seejpeg man/man1/seejpeg.1.gz

.include <bsd.port.mk>
