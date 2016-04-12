# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.8
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mupdf.com/download/ \
		http://www.mupdf.com/download/archive/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libjbig2dec.so:graphics/jbig2dec \
		libopenjp2.so:graphics/openjpeg

CFLAGS+=	-I${WRKSRC}/include/mupdf
LIBS+=		-L${LOCALBASE}/lib
MAKE_ARGS=	build=release prefix=${PREFIX} mandir=${PREFIX}/man verbose=yes
USES=		cpe compiler:c++11-lang gmake jpeg pkgconfig
USE_XORG=	x11 xext

CPE_VENDOR=	artifex

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

OPTIONS_DEFINE=	SCROLL JS
OPTIONS_DEFAULT=SCROLL

SCROLL_DESC=	Build with scroll hacks
JS_DESC=	JavaScript support (V8 engine)

SCROLL_EXTRA_PATCHES=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c
JS_LIB_DEPENDS=		libv8.so:lang/v8
JS_MAKE_ARGS=		V8_PRESENT=1 V8LIBS=-lv8

post-patch:
	@${REINPLACE_CMD} -e 's/-pipe -O2 //' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's/Linux/FreeBSD/' \
		${WRKSRC}/Makerules
	@${REINPLACE_CMD} '/^CFLAGS/s|$$| -I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile
	@${RM} -r ${WRKSRC}/thirdparty/*

post-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} OUT=build/pic XCFLAGS=-fpic libs)

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/pic/libmupdf.a \
		${STAGEDIR}${PREFIX}/lib/libmupdf_pic.a
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 ${STAGEDIR}${PREFIX}/bin/mupdf
.for binary in mutool mujstest mupdf mupdf-x11-curl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${binary}
.endfor

.include <bsd.port.mk>
