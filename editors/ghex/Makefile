PORTNAME=	ghex
PORTVERSION=	46.3
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME hex editor
WWW=		https://gitlab.gnome.org/GNOME/ghex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig tar:xz
USE_GNOME=	cairo glib20 gtk40  introspection:build libadwaita
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.GHex.gschema.xml

# We don't have mremap neither linux/fs.h
MESON_ARGS=	-Dmmap-buffer-backend=false \
		-Ddirect-buffer-backend=false

.include <bsd.port.mk>
