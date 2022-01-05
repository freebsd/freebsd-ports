# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	gtk-update-icon-cache
PORTVERSION=	3.24.31
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
GL_COMMIT=	66d25fb3ec331817e108cd6a2c4020d55e8ba74b

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man-pages

.include <bsd.port.mk>
