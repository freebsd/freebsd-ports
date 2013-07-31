# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libnotify/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libnotify
PORTVERSION=	0.7.5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		yes
USE_GNOME=	intlhack glib20 gdkpixbuf2 ltverhack introspection:build
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
