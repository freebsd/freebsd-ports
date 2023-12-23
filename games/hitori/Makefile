PORTNAME=	hitori
PORTVERSION=	3.38.4
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hitori
WWW=		https://wiki.gnome.org/Apps/Hitori

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome localbase meson pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo gtk30 librsvg2 libxml2:build

GLIB_SCHEMAS=	org.gnome.hitori.gschema.xml

.include <bsd.port.mk>
