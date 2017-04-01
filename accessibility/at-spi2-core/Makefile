# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	at-spi2-core
PORTVERSION=	2.24.0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface

LICENSE=	LGPL21

LIB_DEPENDS=	libdbus-1.so:devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack introspection:build
USE_XORG=	x11 xi xtst xext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-xevie
INSTALL_TARGET=	install-strip

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
