# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notify-osd
PORTVERSION=	0.9.34
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpad.net/notify-osd/precise/0.9.34/+download/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	On-screen-display notification agent using libnotify

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libfontconfig.so:x11-fonts/fontconfig \
		libwnck-3.so:x11-toolkits/libwnck3
RUN_DEPENDS=	dbus-daemon:devel/dbus \
		gsettings-desktop-schemas>=3.28.0:devel/gsettings-desktop-schemas

USES=		gettext-runtime gmake gnome libtool pkgconfig xorg
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USE_XORG=	pixman x11

GNU_CONFIGURE=	yes

CONFLICTS=	xfce4-notification-daemon-[0-9]*

LIBS+=		-L${LOCALBASE}/lib -lpixman-1 -lX11

post-patch:
	@${REINPLACE_CMD} '/SUBDIRS =/s/tests//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
