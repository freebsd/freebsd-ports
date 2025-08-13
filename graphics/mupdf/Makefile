PORTNAME=	mupdf
DISTVERSION=	1.26.5
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mupdf.com/downloads/archive/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Lightweight PDF viewer and toolkit
WWW=		https://www.mupdf.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/ar:devel/binutils
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libbrotlienc.so:archivers/brotli \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgumbo.so:devel/gumbo \
		libharfbuzz.so:print/harfbuzz \
		libjbig2dec.so:graphics/jbig2dec \
		libopenjp2.so:graphics/openjpeg

USES=		compiler:c++20-lang cpe gl gmake jpeg pkgconfig ssl xorg
CPE_VENDOR=	artifex
USE_GL=		gl glut
USE_LDCONFIG=	yes
USE_XORG=	x11 xcursor xext xinerama xrandr

_VERSION_MINOR=	${DISTVERSION:E}
_VERSION_MAJOR=	${DISTVERSION:R:E}
MAKE_ARGS=	AR=${LOCALBASE}/bin/ar \
		build=release \
		mandir=${PREFIX}/share/man \
		prefix=${PREFIX} \
		shared=yes \
		USE_SYSTEM_LIBS=yes \
		verbose=yes \
		XCFLAGS="${CFLAGS} -I${WRKSRC}/include/mupdf -fPIC" \
		XLIB_LDFLAGS="-Wl,-soname,libmupdf.so.${_VERSION_MAJOR}" \
		XLIBS="-L${LOCALBASE}/lib -L${WRKSRC}/build/release ${LDFLAGS}"
ALL_TARGET=	all extra-libs
INSTALL_TARGET=	install install-extra-apps

BINARY_ALIAS=	bash=/bin/sh

PLIST_SUB=	VERSION_MAJOR=${_VERSION_MAJOR} \
		VERSION_MINOR=${_VERSION_MINOR}

OPTIONS_DEFINE=		DOCS JS SCROLL
OPTIONS_DEFAULT=	SCROLL

JS_DESC=	JavaScript support (V8 engine)
SCROLL_DESC=	Build with scroll hacks

JS_LIB_DEPENDS=		libv8.so:lang/v8
JS_MAKE_ARGS=		V8_PRESENT=1 \
			V8LIBS=-lv8
SCROLL_EXTRA_PATCHES=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 \
		${STAGEDIR}${PREFIX}/bin/mupdf

.include <bsd.port.mk>
