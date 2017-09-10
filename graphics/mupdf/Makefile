# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.11
PORTREVISION=	2
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mupdf.com/downloads/ \
		http://www.mupdf.com/downloads/archive/

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Lightweight PDF viewer and toolkit

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjbig2dec.so:graphics/jbig2dec \
		libopenjp2.so:graphics/openjpeg

CFLAGS+=	-I${WRKSRC}/include/mupdf -fPIC
LIBS+=		-L${LOCALBASE}/lib
MAKE_ARGS=	build=release prefix=${PREFIX} mandir=${PREFIX}/man verbose=yes \
		SOVERSION=${PORTVERSION}
USES=		cpe compiler:c++11-lang gmake jpeg pkgconfig
USE_XORG=	x11 xcursor xext xinerama xrandr
USE_GL=		gl
USE_LDCONFIG=	yes

CPE_VENDOR=	artifex

OPTIONS_DEFINE=	JS SCROLL
OPTIONS_DEFAULT=SCROLL

JS_DESC=	JavaScript support (V8 engine)
SCROLL_DESC=	Build with scroll hacks

JS_LIB_DEPENDS=	libv8.so:lang/v8
JS_MAKE_ARGS=	V8_PRESENT=1 V8LIBS=-lv8
SCROLL_EXTRA_PATCHES=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c

PLIST_SUB=	SOVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's/-pipe -O2 //' \
		${WRKSRC}/Makerules
	@${REINPLACE_CMD} -e 's/-ldl //' ${WRKSRC}/Makerules ${WRKSRC}/Makethird
	@${RM} -r ${WRKSRC}/thirdparty/curl \
		${WRKSRC}/thirdparty/freetype \
		${WRKSRC}/thirdparty/harfbuzz \
	 	${WRKSRC}/thirdparty/jbig2dec \
	 	${WRKSRC}/thirdparty/libjpeg \
	 	${WRKSRC}/thirdparty/openjpeg \
	 	${WRKSRC}/thirdparty/zlib

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 ${STAGEDIR}${PREFIX}/bin/mupdf
	${LN} -s libmupdf.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdf.so
	${LN} -s libmupdfthird.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdfthird.so

.include <bsd.port.mk>
