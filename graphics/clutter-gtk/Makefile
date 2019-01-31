# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-gtk
PORTVERSION=	0.10.8
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

DEPRECATED=	0.10.x is unmaintained upstream and unused in the ports tree
EXPIRATION_DATE=	2019-02-28

LIB_DEPENDS=	libclutter-glx-1.0.so:graphics/clutter

PORTSCOUT=	ignore:1

USE_GL=		gl
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomeprefix
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} '/SUBDIRS =/s/examples//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
