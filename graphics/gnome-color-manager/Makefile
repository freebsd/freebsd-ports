PORTNAME=	gnome-color-manager
PORTVERSION=	3.36.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session framework for the GNOME desktop to manage color profiles
WWW=		https://git.gnome.org/browse/gnome-color-manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-sgml>0:textproc/docbook-sgml \
		docbook2man:textproc/docbook-utils \
		itstool:textproc/itstool
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libcolord.so:graphics/colord

USES=		compiler:c++11-lang desktop-file-utils gettext gnome meson \
		pkgconfig tar:xz
USE_GNOME=	gtk30
MESON_ARGS=	-Dtests=false

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
