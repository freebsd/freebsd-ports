# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	at-spi2-atk
PORTVERSION=	2.18.1
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assisted Technology Provider module for GTK+

LICENSE=	LGPL21

BUILD_DEPENDS=	at-spi2-core>=2.17.90:accessibility/at-spi2-core
LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	at-spi2-core>=2.17.90:accessibility/at-spi2-core

PORTSCOUT=	limitw:1,even

USES=		cpe gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	atk glib20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-p2p
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

.include <bsd.port.mk>
