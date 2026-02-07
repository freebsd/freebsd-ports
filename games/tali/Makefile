PORTNAME=	tali
PORTVERSION=	40.9
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Roll dice and score points for the GNOME desktop
WWW=		https://gitlab.gnome.org/GNOME/tali

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support

USES=		gettext gnome localbase meson pkgconfig \
		python:build tar:xz
USE_GNOME=	cairo gtk30 librsvg2 libxml2:build

BINARY_ALIAS=	python3=${PYTHON_CMD}
GLIB_SCHEMAS=	org.gnome.Tali.gschema.xml

#post-install:
#	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games

.include <bsd.port.mk>
