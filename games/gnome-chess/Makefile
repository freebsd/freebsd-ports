PORTNAME=	gnome-chess
PORTVERSION=	47.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME chess
WWW=		https://gitlab.gnome.org/GNOME/gnome-chess

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		desktop-file-utils gettext gnome localbase meson pkgconfig \
		tar:xz vala:build
USE_GNOME=	cairo gtk40 libadwaita librsvg2 libxml2:build

GLIB_SCHEMAS=	org.gnome.Chess.gschema.xml

OPTIONS_DEFINE=		GNUCHESS
OPTIONS_DEFAULT=	GNUCHESS

GNUCHESS_DESC=		Use gnuchess engine for computer player
GNUCHESS_RUN_DEPENDS=	gnuchess:games/gnuchess

.include <bsd.port.mk>
