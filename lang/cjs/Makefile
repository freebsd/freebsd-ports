# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/lang/cjs/Makefile 18985 2014-01-21 12:30:41Z gusi $

PORTNAME=	cjs
PORTVERSION=	2.0.0
CATEGORIES=	lang gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	JavaScript bindings based on gobject-introspection

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs185.so:${PORTSDIR}/lang/spidermonkey185

CONFLICTS_BUILD=spidermonkey17-1.7.*

USES=		gettext gmake pathfix pkgconfig shebangfix
USE_PYTHON_BUILD=yes
USE_GNOME=      cairo glib20 gnomeprefix introspection:build \
		intlhack
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool autoconf automake

CONFIGURE_ARGS+=--enable-compile-warnings=no

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	scripts/make-tests
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcjs*so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cjs-1.0/*so

.include <bsd.port.mk>
