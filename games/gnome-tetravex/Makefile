# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>

PORTNAME=	gnome-tetravex
PORTVERSION=	3.38.2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	80912d06f5e5.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-tetravex/-/merge_requests/20

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome tetravex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix pkgconfig \
		python:3.7+ tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Tetravex.gschema.xml

.include <bsd.port.mk>
