# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.13.0
DISTVERSIONSUFFIX=	-source
PORTREVISION=	4
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

USES=		cpe compiler:c++11-lang gmake jpeg pkgconfig
MAKE_ARGS=	build=release prefix=${PREFIX} mandir=${PREFIX}/man verbose=yes \
		SOVERSION=${PORTVERSION}
ALL_TARGET=	all extra
USE_XORG=	x11 xcursor xext xinerama xrandr
USE_GL=		gl glut
USE_LDCONFIG=	yes

CFLAGS+=	`pkg-config --cflags libopenjp2` -I${WRKSRC}/include/mupdf -fPIC # pkg-config to avoid the conflict with openjpeg15
LIBS+=		-L${LOCALBASE}/lib

CPE_VENDOR=	artifex

OPTIONS_DEFINE=	DOCS JS SCROLL
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
		${WRKSRC}/thirdparty/freeglut \
		${WRKSRC}/thirdparty/harfbuzz \
		${WRKSRC}/thirdparty/jbig2dec \
		${WRKSRC}/thirdparty/libjpeg \
		${WRKSRC}/thirdparty/openjpeg \
		${WRKSRC}/thirdparty/zlib

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 ${STAGEDIR}${PREFIX}/bin/mupdf
	${INSTALL_PROGRAM} \
		${WRKSRC}/build/release/mjsgen \
		${WRKSRC}/build/release/mujstest \
		${WRKSRC}/build/release/mupdf-x11-curl \
		${WRKSRC}/build/release/muraster \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s libmupdf.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdf.so
	${LN} -s libmupdfthird.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdfthird.so

.include <bsd.port.mk>
