# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	exrtools
PORTVERSION=	0.4
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://scanline.ca/exrtools/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for manipulating with HDR images in OpenEXR format

LICENSE=	GPLv2

LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		gmake jpeg pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|<values\.h>|<float.h>|' \
		${WRKSRC}/src/exrnormalize.c \
		${WRKSRC}/src/exrpptm.c \
		${WRKSRC}/src/exrstats.c

.include <bsd.port.mk>
