# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/accessibility/at-spi2-atk/Makefile 313819 2013-03-10 09:18:33Z kwm $
#   $MCom: ports/trunk/accessibility/at-spi2-atk/Makefile 18692 2013-09-22 00:45:30Z kwm $

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

NO_STAGE=	yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomehier intlhack glib20 atk
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-p2p

.include <bsd.port.mk>
