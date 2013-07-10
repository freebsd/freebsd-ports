# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTREVISION=	3
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USES=		gmake
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-opi \
		--with-freetype2-library="${LOCALBASE}/lib" \
		--with-freetype2-includes="${LOCALBASE}/include/freetype2" \
		--bindir="${PREFIX}/libexec/xpdf"

OPTIONS_DEFINE=	LIBPAPER TYPE1 X11
LIBPAPER_DESC=	Enable libpaper
TYPE1_DESC=	Ghostscript type1 fonts
OPTIONS_DEFAULT=	TYPE1 X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTYPE1}
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/n021003l.pfb:${PORTSDIR}/print/gsfonts
.endif

.if ${PORT_OPTIONS:MLIBPAPER}
LIB_DEPENDS+=	paper.2:${PORTSDIR}/print/libpaper
CONFIGURE_ARGS+=--with-libpaper-library="${LOCALBASE}/lib" \
		--with-libpaper-includes="${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=--without-libpaper-library
.endif

.if defined(A4)
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

MAN1=		pdffonts.1 \
		pdfimages.1 \
		pdfinfo.1 \
		pdfdetach.1 \
		pdftoppm.1 \
		pdftops.1 \
		pdftotext.1
MAN5=		xpdfrc.5

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-x
USES+=			motif
MAN1+=			xpdf.1
PLIST_SUB+=		X11=""
.else
PKGNAMESUFFIX+=		-nox11
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|undef USE_COMBO_BOX|define USE_COMBO_BOX 1|' \
		${WRKSRC}/xpdf/XPDFViewer.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE CHANGES README misc/hello.pdf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MX11}
	${LN} -sf ${PREFIX}/libexec/xpdf/xpdf ${PREFIX}/bin/xpdf
.endif

.include <bsd.port.mk>
