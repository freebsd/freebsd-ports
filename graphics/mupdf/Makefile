PORTNAME=	mupdf
DISTVERSION=	1.24.8
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mupdf.com/downloads/archive/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Lightweight PDF viewer and toolkit
WWW=		https://www.mupdf.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjbig2dec.so:graphics/jbig2dec \
		libopenjp2.so:graphics/openjpeg

USES=		compiler:c++11-lang cpe gl gmake jpeg pkgconfig xorg
CPE_VENDOR=	artifex
USE_GL=		gl glut
USE_LDCONFIG=	yes
USE_XORG=	x11 xcursor xext xinerama xrandr

MAKE_ARGS=	build=release \
		mandir=${PREFIX}/share/man \
		prefix=${PREFIX} \
		SOVERSION=${DISTVERSION} \
		verbose=yes \
		XCFLAGS+="-I${WRKSRC}/include/mupdf -fPIC" \
		XLIBS+="-L${LOCALBASE}/lib -L${WRKSRC}/build/release"
ALL_TARGET=	all extra-libs

# pkg-config to avoid the conflict with openjpeg15
CFLAGS+=	`pkg-config --cflags libopenjp2`
LDFLAGS+=	`pkg-config --libs libjpeg libopenjp2` -ljbig2dec

BINARY_ALIAS=	bash=/bin/sh

PLIST_SUB=	SOVERSION=${PORTVERSION}

OPTIONS_DEFINE=		DOCS JS SCROLL
OPTIONS_DEFAULT=	SCROLL

JS_DESC=	JavaScript support (V8 engine)
SCROLL_DESC=	Build with scroll hacks

JS_LIB_DEPENDS=		libv8.so:lang/v8
JS_MAKE_ARGS=		V8_PRESENT=1 \
			V8LIBS=-lv8
SCROLL_EXTRA_PATCHES=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c

post-patch:
	@${REINPLACE_CMD} -e 's/-pipe -O2//' -e 's/-ldl//' ${WRKSRC}/Makerules

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 \
		${STAGEDIR}${PREFIX}/bin/mupdf
	${INSTALL_PROGRAM} \
		${WRKSRC}/build/release/muraster \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s libmupdf.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdf.so
	${LN} -s libmupdf-third.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmupdf-third.so

.include <bsd.port.mk>
