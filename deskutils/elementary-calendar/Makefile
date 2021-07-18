PORTNAME=	elementary-calendar
DISTVERSION=	5.1.1
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Desktop calendar app designed for elementary OS

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libchamplain-0.12.so:graphics/libchamplain \
		libclutter-1.0.so:graphics/clutter \
		libedataserver-1.2.so:databases/evolution-data-server \
		libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libical.so:devel/libical \
		libnotify.so:devel/libnotify

USES=		gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	calendar
USE_GNOME=	glib20 gtk30
GLIB_SCHEMAS=	io.elementary.calendar.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
