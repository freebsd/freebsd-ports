# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtpaint
PORTVERSION=	3.40
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple painting program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libgif.so:graphics/giflib \
		libfreetype.so:print/freetype2

USE_GNOME=	gtk20
USES=		desktop-file-utils gmake iconv jpeg pkgconfig tar:bzip2
HAS_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--localedir=${PREFIX}/share/locale \
		gtk2 cflags asneeded ft jpeg tiff man GIF

OPTIONS_DEFINE=	LCMS2 OPENJPEG NLS
OPTIONS_DEFAULT=	LCMS2 OPENJPEG
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLCMS2}
LIB_DEPENDS+=	liblcms2.so:graphics/lcms2
CONFIGURE_ARGS+=lcms2
.else
CONFIGURE_ARGS+=nolcms
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	libopenjpeg.so:graphics/openjpeg15
CONFIGURE_ARGS+=jp2
.else
LIB_DEPENDS+=	libjasper.so:graphics/jasper
CONFIGURE_ARGS+=jasper
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=intl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
.for lang in cs de es fr gl hu it ja nl pl pt pt_BR ru sk sv tl tr zh_CN zh_TW
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/mtpaint.mo
.endfor

.include <bsd.port.mk>
