PORTNAME=	hitori
PORTVERSION=	44.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hitori puzzle game
WWW=		https://gitlab.gnome.org/GNOME/hitori

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		tar:xz
USE_GNOME=	cairo glib20 gtk30 librsvg2 libxml2:build

GLIB_SCHEMAS=	org.gnome.hitori.gschema.xml

.include <bsd.port.mk>
