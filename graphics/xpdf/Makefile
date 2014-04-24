# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTREVISION=	5
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USES=		gmake
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-opi \
		--with-freetype2-library="${LOCALBASE}/lib" \
		--with-freetype2-includes="${LOCALBASE}/include/freetype2" \
		--bindir="${PREFIX}/libexec/xpdf" \
		--mandir="${PREFIX}/share/xpdf/man"

MANPREFIX=	${PREFIX}/share/xpdf

OPTIONS_DEFINE=	LIBPAPER TYPE1 X11 DOCS
LIBPAPER_DESC=	Enable libpaper
TYPE1_DESC=	Ghostscript type1 fonts
OPTIONS_DEFAULT=	TYPE1 X11
OPTIONS_SUB=		yes

TYPE1_RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/n021003l.pfb:${PORTSDIR}/print/gsfonts

LIBPAPER_LIB_DEPENDS=	libpaper.so:${PORTSDIR}/print/libpaper
LIBPAPER_CONFIGURE_ON=--with-libpaper-library="${LOCALBASE}/lib" \
		--with-libpaper-includes="${LOCALBASE}/include"
LIBPAPER_CONFIGURE_OFF=--without-libpaper-library

.if defined(A4)
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

X11_CONFIGURE_WITH=	x
X11_USES=		motif

post-patch:
	${REINPLACE_CMD} -e 's|undef USE_COMBO_BOX|define USE_COMBO_BOX 1|' \
		${WRKSRC}/xpdf/XPDFViewer.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ANNOUNCE CHANGES README misc/hello.pdf
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${LN} -sf ${PREFIX}/libexec/xpdf/xpdf ${STAGEDIR}${PREFIX}/bin/xpdf

.include <bsd.port.mk>
