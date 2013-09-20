# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://www.mupdf.com/download/
EXTRACT_SUFX=	-source.zip

MAINTAINER=	lichray@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LICENSE=	AGPLv3

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		jbig2dec:${PORTSDIR}/graphics/jbig2dec \
		openjpeg:${PORTSDIR}/graphics/openjpeg

USE_GMAKE=	yes
MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=1 mandir=${PREFIX}/man \
		XCFLAGS=-I${LOCALBASE}/include
USES=		pkgconfig
USE_XORG=	x11 xext
MAN1=		mupdf.1 mutool.1 mudraw.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

OPTIONS_DEFINE=	SCROLL JS
OPTIONS_DEFAULT=SCROLL

SCROLL_DESC=	Build with scroll hacks
JS_DESC=	JavaScript support (V8 engine)

NO_STAGE=	yes
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
LIB_DEPENDS+=	v8:${PORTSDIR}/lang/v8
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
