# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://www.mupdf.com/download/
EXTRACT_SUFX=	-source.zip

MAINTAINER=	lichray@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LICENSE=	AGPLv3

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjbig2dec.so:${PORTSDIR}/graphics/jbig2dec \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15

MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=1 mandir=${PREFIX}/man \
		XCFLAGS=-I${LOCALBASE}/include
USES=		pkgconfig gmake zip
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
EXTRA_PATCHES+=	${FILESDIR}/scroll_hack-apps_pdfapp.c
.endif

.if ${PORT_OPTIONS:MJS}
LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8
MAKE_ARGS+=	V8_PRESENT=1 V8LIBS=-lv8
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} \
		-e '/install:/,/^$$/ { /-d/d; }' \
		-e '/install.*bindir)$$/s/install/$$(BSD_INSTALL_PROGRAM)/' \
		-e '/install.*libdir)$$/s/install/$$(BSD_INSTALL_DATA)/' \
		-e '/install.*incdir)$$/s/install/$$(BSD_INSTALL_DATA)/' \
		-e '/install.*man1$$/s/install/$$(BSD_INSTALL_MAN)/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/-pipe -O2 //' \
		-e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makerules
	${RM} -r ${WRKSRC}/thirdparty/*

.include <bsd.port.mk>
