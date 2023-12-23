PORTNAME=	atomix
PORTVERSION=	3.34.0
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Yet another little mind game
WWW=		https://wiki.gnome.org/Apps/Atomix

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support

PORTSCOUT=	limitw:1,even

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30
LDFLAGS=	-lm

.include <bsd.port.mk>
