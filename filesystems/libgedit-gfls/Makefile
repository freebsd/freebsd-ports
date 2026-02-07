PORTNAME=	libgedit-gfls
DISTVERSION=	0.3.0
CATEGORIES=	filesystems gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File loading and saving for Gedit
WWW=		https://gitlab.gnome.org/World/gedit/libgedit-gfls

LICENSE=	LGPL3+

USES=		gettext gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20 gtk30 introspection:build

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit

MESON_ARGS=	-Dgtk_doc=false \
		-Dtests=false

.include <bsd.port.mk>
