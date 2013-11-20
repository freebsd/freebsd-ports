# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/accessibility/at-spi2-core/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom: ports/trunk/accessibility/at-spi2-core/Makefile 18692 2013-09-22 00:45:30Z kwm $

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

NO_STAGE=	yes
USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	gnomehier glib20 intlhack introspection:build
USE_XORG=	x11 xi xtst xext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-xevie
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
