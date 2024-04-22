PORTNAME=	seejpeg
PORTVERSION=	1.10
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/viewers/svga

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console graphics viewer using the svga console graphics library
WWW=		https://www.icewalk.com/softlib/app/app_00013.html

LIB_DEPENDS=	libvga.so:graphics/svgalib

USES=		gmake jpeg tar:tgz
ALL_TARGET=	seejpeg
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/seejpeg share/man/man1/seejpeg.1.gz

.include <bsd.port.mk>
