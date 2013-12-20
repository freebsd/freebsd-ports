# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/lang/gjs/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gjs
PORTVERSION=	1.34.0
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs185.so:${PORTSDIR}/lang/spidermonkey185

CONFLICTS_BUILD=spidermonkey17-1.7.*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig shebangfix
USE_PYTHON_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo glib20 gnomeprefix introspection:build \
		intlhack ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	scripts/make-tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gjs-1.0/*.so

.include <bsd.port.mk>
