PORTNAME=	gnome-tetravex
PORTVERSION=	3.38.2
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	80912d06f5e5.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-tetravex/-/merge_requests/20

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome tetravex
WWW=		https://wiki.gnome.org/Apps/Tetravex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix pkgconfig \
		python tar:xz vala:build
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Tetravex.gschema.xml

.include <bsd.port.mk>
