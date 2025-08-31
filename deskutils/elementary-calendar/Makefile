PORTNAME=	calendar
DISTVERSION=	8.0.0
PORTREVISION=	1
CATEGORIES=	deskutils
PKGNAMEPREFIX=	elementary-

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Desktop calendar app designed for elementary OS
WWW=		https://github.com/elementary/calendar

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libical-glib.so:devel/libical \
		libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3 \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	consolekit2>0:sysutils/consolekit2

USES=		desktop-file-utils gettext gnome meson pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	evolutiondataserver3 gdkpixbuf glib20 gtk30
GLIB_SCHEMAS=	io.elementary.calendar.gschema.xml

.include <bsd.port.mk>
