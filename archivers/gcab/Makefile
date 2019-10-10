# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	gcab
PORTVERSION=	1.0
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library to create cabinet files

BUILD_DEPENDS=	vala:lang/vala \
		gtkdoc-scan:textproc/gtk-doc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
CPE_VENDOR=	gnome

.include <bsd.port.mk>
