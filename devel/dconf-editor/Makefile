PORTNAME=	dconf-editor
PORTVERSION=	45.0.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

# https://gitlab.gnome.org/GNOME/dconf-editor/-/merge_requests/34
PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES=	baf18373.patch:-p1 \
		dd8ddbbf.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Viewer and editor of applications internal settings
WWW=		https://gitlab.gnome.org/GNOME/dconf-editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy \
		libdconf.so:devel/dconf
RUN_DEPENDS=	dconf>0:devel/dconf \
		dbus>0:devel/dbus

USES=		desktop-file-utils gettext gnome localbase meson pkgconfig tar:xz \
		vala:build
USE_GNOME=	glib20 gtk30 libxml2:build
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml

.include <bsd.port.mk>
