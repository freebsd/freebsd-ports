# New ports collection makefile for:	xpdf
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-opi \
		--with-freetype2-library="${LOCALBASE}/lib" \
		--with-freetype2-includes="${LOCALBASE}/include/freetype2/" \
		--bindir="${PREFIX}/libexec/xpdf"

OPTIONS=	LIBPAPER "Enable libpaper"      off     \
		TYPE1	"Ghostscript type1 fonts" on \
		X11     "Enable X11 support"    on      \

.include <bsd.port.options.mk>

.if defined(WITH_TYPE1)
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/n021003l.pfb:${PORTSDIR}/print/gsfonts
.endif

.if defined(WITH_LIBPAPER)
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

.if defined(WITHOUT_X11)
PKGNAMESUFFIX+=		-nox11
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.else
CONFIGURE_ARGS+=	--with-x
USE_MOTIF=		yes
MAN1+=			xpdf.1
PLIST_SUB+=		X11=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|undef USE_COMBO_BOX|define USE_COMBO_BOX 1|' \
		${WRKSRC}/xpdf/XPDFViewer.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE CHANGES README misc/hello.pdf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(WITHOUT_X11)
	${LN} -sf ${PREFIX}/libexec/xpdf/xpdf ${PREFIX}/bin/xpdf
.endif

.include <bsd.port.mk>
