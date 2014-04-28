# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/lang/gjs/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	gjs
PORTVERSION=	1.40.1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs-24.so:${PORTSDIR}/lang/spidermonkey24

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	cairo glib20 gnomeprefix introspection:build \
		intlhack
USE_PYTHON_BUILD=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgjs.so.*

.include <bsd.port.mk>
