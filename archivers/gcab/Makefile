PORTNAME=	gcab
PORTVERSION=	1.6
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library to create cabinet files
WWW=		https://wiki.gnome.org/msitools

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext gnome meson pkgconfig tar:xz vala:build
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	-Ddocs=false

.include <bsd.port.mk>
