PORTNAME=	gnome-chess
PORTVERSION=	42.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome chess

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		itstool:textproc/itstool \
		vala:lang/vala
LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gl gnome localbase meson pkgconfig \
		python:3.6+,build tar:xz
USE_GNOME=	cairo gtk40 librsvg2 libxml2:build
USE_GL=		egl gl
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Chess.gschema.xml

OPTIONS_DEFINE=		GNUCHESS
OPTIONS_DEFAULT=	GNUCHESS

GNUCHESS_DESC=		Use gnuchess engine for computer player
GNUCHESS_RUN_DEPENDS=	gnuchess:games/gnuchess

.include <bsd.port.mk>
