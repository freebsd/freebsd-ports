# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/lang/gjs/Makefile,v 1.28 2012/10/18 08:57:51 kwm Exp $

PORTNAME=	gjs
PORTVERSION=	1.32.0
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		spidermonkey185>=1.8.5:${PORTSDIR}/lang/spidermonkey185
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cairo:${PORTSDIR}/graphics/cairo \
		mozjs185:${PORTSDIR}/lang/spidermonkey185

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON_BUILD=yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack glib20 ltverhack
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/scripts/make-tests

.include <bsd.port.mk>
