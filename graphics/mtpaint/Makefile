# New ports collection makefile for:	mtpaint
# Date created:		3 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mtpaint
PORTVERSION=	3.40
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple painting program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

OPTIONS=	GIFLIB "Enable LZW-compressed GIF support" off \
		LCMS2 "Enable ICC color management support" on \
		OPENJPEG "Enable OpenJPEG support" on \
		NLS "Enable Native Language support" on

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--localedir=${PREFIX}/share/locale \
		gtk2 cflags asneeded ft jpeg tiff man
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1

.include <bsd.port.options.mk>

.if defined(WITH_GIFLIB)
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
CONFIGURE_ARGS+=GIF
.else
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
CONFIGURE_ARGS+=gif
.endif

.if defined(WITHOUT_LCMS2)
CONFIGURE_ARGS+=nolcms
.else
LIB_DEPENDS+=	lcms2.2:${PORTSDIR}/graphics/lcms2
CONFIGURE_ARGS+=lcms2
.endif

.if defined(WITHOUT_OPENJPEG)
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=jasper
.else
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
CONFIGURE_ARGS+=jp2
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=intl
PLIST_SUB+=	NLS=""
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.png \
		${PREFIX}/share/pixmaps
.if !defined(WITHOUT_NLS)
.for lang in cs de es fr gl hu it ja nl pl pt pt_BR ru sk sv tl tr zh_CN zh_TW
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/mtpaint.mo
.endfor
.endif

.include <bsd.port.mk>
