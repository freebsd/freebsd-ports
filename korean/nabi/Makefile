# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nabi
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	korean gnome

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhangul.so:korean/libhangul
LIB_DEPENDS+=	libfreetype.so:print/freetype2
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig

GH_ACCOUNT=	choehwanjin
GH_TAGNAME=	f08d7d3
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
USES=		autoreconf gmake gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	ice sm x11

OPTIONS_DEFINE=	NLS
OPTIONS_RADIO=	LAYOUT
OPTIONS_RADIO_LAYOUT=	LAYOUT_390 LAYOUT_FINAL
OPTIONS_SUB=	yes
LAYOUT_DESC=	Select 3-beolsik layout (default: 2-beolsik)
LAYOUT_390_DESC=	3-beolsik 390 keyboard
LAYOUT_FINAL_DESC=	3-beolsik final keyboard
LAYOUT_390_CONFIGURE_ON=	--with-default-keyboard=39
LAYOUT_FINAL_CONFIGURE_ON=	--with-default-keyboard=3f
NLS_USES=	gettext localbase

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS /s| po||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^po\/Makefile\.in/d' ${WRKSRC}/configure.ac

pre-configure-NLS-on:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/glib-gettextize)

.include <bsd.port.mk>
