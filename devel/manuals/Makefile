PORTNAME=	manuals
DISTVERSION=	49.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Browse, search GNOME developer documentation
WWW=		https://gitlab.gnome.org/GNOME/manuals

LICENSE=	GPLv3+

BUILD_DEPENDS=	appstreamcli:devel/appstream
LIB_DEPENDS=	libgom-1.0.so:databases/gom \
		libdex-1.so:devel/libdex \
		libpanel-1.so:x11-toolkits/libpanel \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60 \
		libfoundry-1.so:devel/foundry

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson \
		pkgconfig tar:xz
USE_GNOME=	glib20 gtk40 libadwaita
GLIB_SCHEMAS=	app.devsuite.Manuals.gschema.xml

PORTSCOUT=	limit:^49\.

.include <bsd.port.mk>
