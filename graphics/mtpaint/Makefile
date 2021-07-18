# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	mtpaint
DISTVERSION=	3.50.09
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple painting program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gmake gnome iconv jpeg pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	wjaguar
GH_PROJECT=	mtPaint
GH_TAGNAME=	4ea607e
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/share/man/man1 \
		--localedir=${PREFIX}/share/locale \
		asneeded gtk3 cflags ft jpeg man tiff

CFLAGS+=	-fcommon
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PORTDOCS=	NEWS README

OPTIONS_DEFINE=		DOCS LCMS2 NLS OPENJPEG WEBP
OPTIONS_DEFAULT=	LCMS2 OPENJPEG WEBP
OPTIONS_SUB=		yes

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_ON=	lcms2
LCMS2_CONFIGURE_OFF=	nolcms
NLS_USES=		gettext
NLS_CONFIGURE_ON=	intl
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_LIB_DEPENDS_OFF=libjasper.so:graphics/jasper
OPENJPEG_CONFIGURE_ON=	jp2v2
OPENJPEG_CONFIGURE_OFF=	jasper
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_ON=	webp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-NLS-on:
.for lang in cs de es fr gl hu it ja kab nl pl pt pt_BR ru sk sv tl tr zh_CN zh_TW
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/mtpaint.mo
.endfor

.include <bsd.port.mk>
