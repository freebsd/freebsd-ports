# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/at-spi2-core/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	at-spi2-core
PORTVERSION=	2.12.0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface

LICENSE=	LGPL21

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier intlhack introspection:build
USE_XORG=	x11 xi xtst xext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-xevie
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libatspi.so.0

.include <bsd.port.mk>
