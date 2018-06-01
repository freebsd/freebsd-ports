# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	leptonica
PORTVERSION=	1.76.0
CATEGORIES=	graphics

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	C library for efficient image processing and image analysis operations

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libopenjp2.so:graphics/openjpeg \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

LICENSE_FILE=	leptonica-license.txt

CONFLICTS=	leptonlib-[0-9]*
CONFLICTS_BUILD=	openjpeg15

USES=		autoreconf jpeg libtool pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	DanBloomberg

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

TESTS?=	generate compare
.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	${LOCALBASE}/bin/gnuplot:math/gnuplot
.endif
#the display portion of the regression tests is interactive,
#and requires the use of xv, xli or xzgv as an image viewer
.if defined(MAINTAINER_MODE) && !defined(BATCH)
TESTS+=	display
.endif

check regression-test test: build
.for c in ${TESTS}
	@cd ${WRKSRC}/prog; ${SETENV} \
	LD_LIBRARY_PATH="${WRKSRC}/src/.libs:${LOCALBASE}/lib" \
	${WRKSRC}/prog/alltests_reg ${c}
.endfor

.include <bsd.port.mk>
