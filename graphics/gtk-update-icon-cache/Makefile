# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-update-icon-cache
PORTVERSION=	3.24.20
CATEGORIES=	graphics
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Gtk-update-icon-cache utility from the Gtk+ toolkit

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome meson pkgconfig
USE_GNOME=	gdkpixbuf2
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	Community/gentoo
GL_COMMIT=	667cc0e1cdfd63a49703fe37228b0550e9f91f73

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MANPAGES_MESON_TRUE=	man-pages

.include <bsd.port.mk>
