# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	gtk-update-icon-cache
PORTVERSION=	3.24.26
PORTREVISION=	1
CATEGORIES=	graphics
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Gtk-update-icon-cache utility from the Gtk+ toolkit

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome meson pkgconfig trigger
USE_GNOME=	gdkpixbuf2
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	Community/gentoo
GL_COMMIT=	5d5d06c43e088b527a283d8eae37e9ef3ea0d7ea

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man-pages

.include <bsd.port.mk>
