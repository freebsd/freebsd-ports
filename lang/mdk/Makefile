# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdk
PORTVERSION=	1.2.9
PORTREVISION=	4
CATEGORIES=	lang gnome
MASTER_SITES=	GNU/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities for developing programs using MIX and MIXAL

LICENSE=	GPLv3

USE_GNOME=	glib20 intltool
USES=		gettext gmake ncurses pkgconfig readline:port
GNU_CONFIGURE=	yes
TEST_TARGET=	check

INFO=		mdk
PLIST_FILES=	bin/mixasm \
		bin/mixvm \
		share/locale/de/LC_MESSAGES/mdk.mo \
		%%DATADIR%%/mixal-mode.el \
		%%DATADIR%%/mixvm.el

OPTIONS_DEFINE=	GLADE GUILE
OPTIONS_DEFAULT=GLADE GUILE

GLADE_CONFIGURE_ENABLE=	gui
GLADE_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
GLADE_USE=		GNOME=cairo,gdkpixbuf2,libglade2
GLADE_PLIST_FILES=	bin/gmixvm \
			%%DATADIR%%/mixgtk.glade

GUILE_CONFIGURE_WITH=	guile
GUILE_LIB_DEPENDS=	libguile-2.0.so:lang/guile2 \
			libgc-threaded.so:devel/boehm-gc-threaded
GUILE_PLIST_FILES=	bin/mixguile \
			%%DATADIR%%/mixguile.scm \
			%%DATADIR%%/mixguile-commands.scm \
			%%DATADIR%%/mixguile-vm-stat.scm

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-patch-GLADE-on:
# Fix path in command for default external editor
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/mixgtk/Makefile.in

.include <bsd.port.mk>
