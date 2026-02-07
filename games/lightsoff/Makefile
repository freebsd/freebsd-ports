PORTNAME=	lightsoff
PORTVERSION=	48.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME ligthsoff
WWW=		https://gitlab.gnome.org/GNOME/lightsoff

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext gnome localbase meson pkgconfig tar:xz vala:build
USE_GNOME=	cairo glib20 gtk40 libadwaita

GLIB_SCHEMAS=	org.gnome.LightsOff.gschema.xml

.include <bsd.port.mk>
