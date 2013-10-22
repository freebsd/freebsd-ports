# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtpaint
PORTVERSION=	3.40
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple painting program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gif.5:${PORTSDIR}/graphics/giflib \
		freetype.9:${PORTSDIR}/print/freetype2

OPTIONS_DEFINE=	LCMS2 OPENJPEG NLS
OPTIONS_DEFAULT=	LCMS2 OPENJPEG
OPENJPEG_DESC=	Enable OpenJPEG support

USE_BZIP2=	yes
USE_GNOME=	gtk20
USES=		gmake pkgconfig iconv
HAS_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--localedir=${PREFIX}/share/locale \
		gtk2 cflags asneeded ft jpeg tiff man GIF

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLCMS2}
LIB_DEPENDS+=	lcms2.2:${PORTSDIR}/graphics/lcms2
CONFIGURE_ARGS+=lcms2
.else
CONFIGURE_ARGS+=nolcms
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
CONFIGURE_ARGS+=jp2
.else
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=jasper
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=intl
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.png \
		${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MNLS}
.for lang in cs de es fr gl hu it ja nl pl pt pt_BR ru sk sv tl tr zh_CN zh_TW
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/mtpaint.mo
.endfor
.endif

.include <bsd.port.mk>
