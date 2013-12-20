# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/at-spi2-atk/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	at-spi2-atk
PORTVERSION=	2.8.0
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

USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomehier intlhack glib20 atk
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-p2p

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libatk-bridge-2.0.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/modules/libatk-bridge.so

.include <bsd.port.mk>
