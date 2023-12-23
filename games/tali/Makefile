PORTNAME=	tali
PORTVERSION=	40.8
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome tali
WWW=		https://wiki.gnome.org/Apps/Tali

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig \
		python:build tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build

BINARY_ALIAS=	python3=${PYTHON_CMD}
GLIB_SCHEMAS=	org.gnome.Tali.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games

.include <bsd.port.mk>
