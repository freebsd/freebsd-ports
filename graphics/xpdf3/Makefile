# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.04
PORTREVISION=	9
CATEGORIES=	graphics print
MASTER_SITES=	http://mirrors.rit.edu/zi/ \
		ftp://ftp.foolabs.com/pub/xpdf/ \
		TEX_CTAN/support/xpdf \
		http://komquats.com/distfiles/
.if !defined(MASTERDIR)
PKGNAMESUFFIX=  3
CONFLICTS_INSTALL=	xpdf4-* xpdf-*
.else
CONFLICTS_INSTALL=	xpdf4-*	xpdf3-*
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		gmake cpe localbase
CPE_VENDOR=	foolabs
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

SUB_FILES=	xpdf-man.conf

TYPE1_RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/n021003l.pfb:print/gsfonts

LIBPAPER_LIB_DEPENDS=	libpaper.so:print/libpaper
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
	@cd ${STAGEDIR}${PREFIX}; \
	${LN} -sf ../libexec/xpdf/xpdf bin/xpdf
	${INSTALL_DATA} ${WRKDIR}/xpdf-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/xpdf.conf

.include <bsd.port.mk>
