# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdk
PORTVERSION=	1.2.10
CATEGORIES=	lang gnome
MASTER_SITES=	GNU/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for developing programs using MIX and MIXAL

LICENSE=	GPLv3

USES=		gettext gmake gnome ncurses pkgconfig readline:port
USE_GNOME=	glib20 intltool
GNU_CONFIGURE=	yes
TEST_TARGET=	check

INFO=		mdk

OPTIONS_DEFINE=	GLADE GUILE NLS
OPTIONS_DEFAULT=GLADE GUILE
OPTIONS_SUB=	yes

GLADE_CONFIGURE_ENABLE=	gui
GLADE_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GLADE_USE=		GNOME=cairo,gdkpixbuf2,libglade2

GUILE_CONFIGURE_WITH=	guile
GUILE_LIB_DEPENDS=	libguile-2.0.so:lang/guile2 \
			libgc-threaded.so:devel/boehm-gc-threaded

NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-patch-GLADE-on:
# Fix path in command for default external editor
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/mixgtk/Makefile.in

.include <bsd.port.mk>
