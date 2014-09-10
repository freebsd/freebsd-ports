# Created by: Eric Turgeon <ericturgeon@ghostbsd.org>
# $FreeBSD$

PORTNAME=	caja-extensions
PORTVERSION=	1.8.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Caja extension which allows you to open a terminal

LIB_DEPENDS=	libgupnp-1.0.so:${PORTSDIR}/net/gupnp

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	caja desktop
USE_GNOME=	glib20 gnomehier intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
