# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-gtk
PORTVERSION=	0.10.8
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter

USE_BZIP2=	yes
USE_GL=		gl
USES=		gettext gmake libtool:keepla pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomeprefix
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
