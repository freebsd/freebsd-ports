# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/graphics/clutter/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	clutter
PORTVERSION=	1.12.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libcogl.so:${PORTSDIR}/graphics/cogl

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gdkpixbuf2 ltverhack gnomeprefix atk pango \
		introspection:build
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--disable-gdk-backend

CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libclutter-1.0.so.0

.include <bsd.port.mk>
