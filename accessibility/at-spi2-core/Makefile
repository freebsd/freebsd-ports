# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/at-spi2-core/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	at-spi2-core
PORTVERSION=	2.8.0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface

LICENSE=	LGPL21

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	gnomehier glib20 intlhack introspection:build
USE_XORG=	x11 xi xtst xext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-xevie
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libatspi.so.0

.include <bsd.port.mk>
