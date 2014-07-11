# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports-experimental/trunk/graphics/clutter/Makefile 19523 2014-04-14 23:10:58Z gusi $

PORTNAME=	clutter
PORTVERSION=	1.18.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libcogl.so:${PORTSDIR}/graphics/cogl

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gdkpixbuf2 gnomeprefix atk pango \
		introspection:build
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--disable-gdk-backend

CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
