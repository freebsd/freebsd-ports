# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libnotify/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libnotify
PORTVERSION=	0.7.5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		yes
USE_GNOME=	intlhack glib20 gdkpixbuf2 ltverhack introspection
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnotify.so.4

.include <bsd.port.mk>
