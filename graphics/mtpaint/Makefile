# New ports collection makefile for:	mtpaint
# Date created:		3 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mtpaint
PORTVERSION=	3.31
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple painting program

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		openjpeg.2:${PORTSDIR}/graphics/openjpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--locale=${PREFIX}/share/locale \
		gtk2 cflags slow asneeded gif jpeg jp2 tiff man

MANCOMPRESSED=	yes
MAN1=		${PORTNAME}.1

CFLAGS+=	-DU_FREETYPE

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=intl
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|="/usr"|="${LOCALBASE}"|g ; \
		 s|/usr/X11R6|${LOCALBASE}|g ; \
		 s|GTK_LIB -s|GTK_LIB|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1.gz \
		${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.png \
		${PREFIX}/share/pixmaps
.if !defined(WITHOUT_NLS)
.for lang in cs de es fr gl it ja nl pl pt pt_BR ru sk sv tr zh_CN zh_TW
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/mtpaint.mo
.endfor
.endif

.include <bsd.port.mk>
