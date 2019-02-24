# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
DISTVERSION=	1.14.0
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
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

USES=		cpe compiler:c++11-lang gl gmake jpeg pkgconfig
USE_XORG=	x11 xcursor xext xinerama xrandr
USE_GL=		gl glut
CPE_VENDOR=	artifex
USE_LDCONFIG=	yes

# pkg-config to avoid the conflict with openjpeg15
CFLAGS+=	`pkg-config --cflags libopenjp2`

MAKE_ARGS=	build=release prefix=${PREFIX} mandir=${PREFIX}/man verbose=yes \
		XCFLAGS+="-I${WRKSRC}/include/mupdf -fPIC" \
		XLIBS+="-L${LOCALBASE}/lib -L${WRKSRC}/build/release" \
		SOVERSION=${DISTVERSION}
ALL_TARGET=	all extra

OPTIONS_DEFINE=	DOCS JS SCROLL
OPTIONS_DEFAULT=	SCROLL

JS_DESC=	JavaScript support (V8 engine)
SCROLL_DESC=	Build with scroll hacks

JS_LIB_DEPENDS=	libv8.so:lang/v8
JS_MAKE_ARGS=	V8_PRESENT=1 V8LIBS=-lv8
SCROLL_EXTRA_PATCHES=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c

PLIST_SUB=	SOVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's/-pipe -O2 //' \
		${WRKSRC}/Makerules
	@${REINPLACE_CMD} -e 's/-ldl //' ${WRKSRC}/Makerules \
		${WRKSRC}/Makethird

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 \
		${STAGEDIR}${PREFIX}/bin/mupdf
	${INSTALL_PROGRAM} \
		${WRKSRC}/build/release/mjsgen \
		${WRKSRC}/build/release/mujstest \
		${WRKSRC}/build/release/muraster \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s libmupdf.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdf.so
	${LN} -s libmupdf-third.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdf-third.so

.include <bsd.port.mk>
