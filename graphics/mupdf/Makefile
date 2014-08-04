# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://www.mupdf.com/download/
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LICENSE=	AGPLv3

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjbig2dec.so:${PORTSDIR}/graphics/jbig2dec \
		libopenjp2.so:${PORTSDIR}/graphics/openjpeg

MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=1 mandir=${PREFIX}/man \
			HAVE_X11=yes \
			XCFLAGS="`pkg-config --cflags freetype2` -I ${LOCALBASE}/include" \
			XLIBS="`pkg-config --libs freetype2 libopenjp2 x11 xext` -ljpeg -ljbig2dec"
USES=		pkgconfig gmake
USE_XORG=	x11 xext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

OPTIONS_DEFINE=	SCROLL JS
OPTIONS_DEFAULT=SCROLL

SCROLL_DESC=	Build with scroll hacks
JS_DESC=	JavaScript support (V8 engine)

.include <bsd.port.options.mk>

.if ${CC:T:Mclang} == "clang"
CFLAGS+=	-no-integrated-as
.elif ${ARCH} == "amd64" || ${ARCH} == "i386"
CFLAGS+=	-mfpmath=sse
.endif

.if ${PORT_OPTIONS:MSCROLL}
EXTRA_PATCHES+=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c
.endif

.if ${PORT_OPTIONS:MJS}
LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8
MAKE_ARGS+=	V8_PRESENT=1 V8LIBS=-lv8
.endif

post-patch:
	${REINPLACE_CMD} -e 's/-pipe -O2 //' \
		-e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makerules
	${RM} -r ${WRKSRC}/thirdparty/*

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 ${STAGEDIR}${PREFIX}/bin/mupdf
.for binary in mudraw mutool mujstest mupdf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${binary}
.endfor

.include <bsd.port.mk>
