PORTNAME=	gnome-robots
DISTVERSION=	41.2
PORTREVISION=	3
CATEGORIES=	games gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME robots
WWW=		https://gitlab.gnome.org/GNOME/gnome-robots

LICENSE=	GPLv3+

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo desktop-file-utils gettext gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20 gtk40 libadwaita librsvg2 libxml2

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

GLIB_SCHEMAS=	org.gnome.Robots.gschema.xml

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gnome-robots

.include <bsd.port.mk>
