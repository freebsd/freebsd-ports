PORTNAME=	template-glib
PORTVERSION=	3.36.1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Templating library for GLib
WWW=		https://gitlab.gnome.org/GNOME/template-glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		bison compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection

.include <bsd.port.mk>
