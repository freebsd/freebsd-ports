# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/graphics/cogl/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	cogl
PORTVERSION=	1.12.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter OpenGL abstraction library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	clutter-1.6.[0-9]*

USES=		gettext gmake libtool pathfix pkgconfig
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GNOME=	gdkpixbuf2 gnomeprefix atk pango introspection:build
USE_GL=		gl
USE_XORG=	x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
