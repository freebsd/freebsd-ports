# $FreeBSD$

PORTNAME=	libgnome-games-support
PORTVERSION=	1.2.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small library intended for internal use by GNOME Games

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee

BROKEN=		does not build (Package dependency requirement 'gtk+-3.0 >= 3.19.2' could not be satisfied)

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome pathfix libtool pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
