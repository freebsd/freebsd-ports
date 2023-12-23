PORTNAME=	calendar
DISTVERSION=	6.1.2
PORTREVISION=	2
CATEGORIES=	deskutils
PKGNAMEPREFIX=	elementary-

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Desktop calendar app designed for elementary OS
WWW=		https://github.com/elementary/calendar

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libchamplain-0.12.so:graphics/libchamplain \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libical.so:devel/libical \
		libnotify.so:devel/libnotify \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	consolekit2>0:sysutils/consolekit2

USES=		desktop-file-utils gettext gnome meson pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	gdkpixbuf2 glib20 gtk30 evolutiondataserver3
GLIB_SCHEMAS=	io.elementary.calendar.gschema.xml

.include <bsd.port.mk>
