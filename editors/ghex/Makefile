PORTNAME=	ghex
PORTVERSION=	46.2
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME hex editor
WWW=		https://wiki.gnome.org/Apps/Ghex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext desktop-file-utils gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk40  libadwaita introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.GHex.gschema.xml

# We don't have mremap neither linux/fs.h
MESON_ARGS=	-Dmmap-buffer-backend=false \
		-Ddirect-buffer-backend=false


.include <bsd.port.mk>
