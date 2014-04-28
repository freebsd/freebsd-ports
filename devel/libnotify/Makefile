# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libnotify/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	libnotify
PORTVERSION=	0.7.6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	intlhack glib20 gdkpixbuf2 introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
