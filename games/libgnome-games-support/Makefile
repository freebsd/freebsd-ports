PORTNAME=	libgnome-games-support
PORTVERSION=	1.8.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small library intended for internal use by GNOME Games

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee

PORTSCOUT=	limitw:1,even

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30

.include <bsd.port.mk>
