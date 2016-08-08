# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notify-osd
PORTVERSION=	0.9.29
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/43419242/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	On-screen-display notification agent using libnotify

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	dbus-daemon:devel/dbus

CONFLICTS=	xfce4-notification-daemon-[0-9]*

GNU_CONFIGURE=	yes
USES=		gettext-runtime gmake libtool pkgconfig
USE_GNOME=	cairo gconf2 gdkpixbuf2 libwnck
USE_XORG=	pixman x11

LIBS+=		-L${LOCALBASE}/lib -lpixman-1 -lX11

post-patch:
	@${REINPLACE_CMD} '/SUBDIRS =/s/tests//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
