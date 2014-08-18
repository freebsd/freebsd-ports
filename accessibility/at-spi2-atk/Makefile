# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/at-spi2-atk/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	at-spi2-atk
PORTVERSION=	2.12.1
PORTREVISION=	1
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assisted Technology Provider module for GTK+

LICENSE=	LGPL21

BUILD_DEPENDS=	at-spi2-core>=2.8.0:${PORTSDIR}/accessibility/at-spi2-core
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	at-spi2-core>=2.8.0:${PORTSDIR}/accessibility/at-spi2-core

PORTSCOUT=	limitw:1,even

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	atk glib20 gnomehier intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-p2p
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
