# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	exrtools
PORTVERSION=	0.4
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	http://scanline.ca/exrtools/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for manipulating with HDR images in OpenEXR format

LICENSE=	GPLv2

LIB_DEPENDS=	libImath.so:graphics/ilmbase \
		libpng.so:graphics/png \
		libIlmImf.so:graphics/openexr

USES=		compiler:c++11-lang gmake jpeg localbase:ldflags pkgconfig

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<values\.h>|<float.h>|' \
		${WRKSRC}/src/exrnormalize.c \
		${WRKSRC}/src/exrpptm.c \
		${WRKSRC}/src/exrstats.c

.include <bsd.port.mk>
