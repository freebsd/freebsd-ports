# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	tali
PORTVERSION=	40.4
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	79509bf3e945.patch:-p1 # https://gitlab.gnome.org/GNOME/tali/-/merge_requests/14

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome tali

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig \
		python:3.6+,build tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build

BINARY_ALIAS=	python3=${PYTHON_CMD}
GLIB_SCHEMAS=	org.gnome.Tali.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games

.include <bsd.port.mk>
