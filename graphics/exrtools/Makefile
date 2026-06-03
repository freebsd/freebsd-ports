PORTNAME=	exrtools
DISTVERSION=	0.5
CATEGORIES=	graphics
MASTER_SITES=	http://scanline.ca/exrtools/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for manipulating with HDR images in OpenEXR format
WWW=		http://scanline.ca/exrtools/

LICENSE=	GPLv2

LIB_DEPENDS=	libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gmake jpeg localbase:ldflags pkgconfig

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<values\.h>|<float.h>|' \
		${WRKSRC}/src/exrlmspptm.c \
		${WRKSRC}/src/exrluminance.c \
		${WRKSRC}/src/exrppnew.c \
		${WRKSRC}/src/exrhistogram.c \
		${WRKSRC}/src/exrxyz.c \
		${WRKSRC}/src/exrnormalize.c \
		${WRKSRC}/src/exrclip.c \
		${WRKSRC}/src/exrexpand.c \
		${WRKSRC}/src/exrbiggstm.c \
		${WRKSRC}/src/exrcompare.c \
		${WRKSRC}/src/exriptpp.c \
		${WRKSRC}/src/exrpptm.c \
		${WRKSRC}/src/exrstats.c \
		${WRKSRC}/src/exrbiggsrev.c \
		${WRKSRC}/src/exraverage.c

.include <bsd.port.mk>
