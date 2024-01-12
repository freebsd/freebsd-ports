PORTNAME=	gcab
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library to create cabinet files
WWW=		https://wiki.gnome.org/msitools

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build
CPE_VENDOR=	gnome

MESON_ARGS=	-Ddocs=false

.include <bsd.port.mk>
