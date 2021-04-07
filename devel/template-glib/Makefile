PORTNAME=	template-glib
PORTVERSION=	3.34.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Templating library for GLib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		bison compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection

.include <bsd.port.mk>
