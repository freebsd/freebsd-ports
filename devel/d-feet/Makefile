PORTNAME=	d-feet
PORTVERSION=	0.3.16
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	05465d486afd.patch:-p1 # https://gitlab.gnome.org/GNOME/d-feet/-/merge_requests/32

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus Python introspection debugger
WWW=		https://wiki.gnome.org/Apps/DFeet

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext gnome meson pkgconfig python tar:xz
USE_GNOME=	gtk30 libwnck3 pygobject3 introspection:build
GLIB_SCHEMAS=	org.gnome.dfeet.gschema.xml

MESON_ARGS=	-Dpython="${PYTHON_CMD}" -Dtests=false

NO_ARCH=	yes

.include <bsd.port.mk>
