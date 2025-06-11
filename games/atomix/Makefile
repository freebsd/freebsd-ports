PORTNAME=	atomix
PORTVERSION=	44.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Yet another little mind game
WWW=		https://gitlab.gnome.org/GNOME/atomix

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf glib20 gtk30
LDFLAGS=	-lm

.include <bsd.port.mk>
