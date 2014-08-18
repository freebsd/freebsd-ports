# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/lang/cjs/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	cjs
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JavaScript bindings based on gobject-introspection

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs185.so:${PORTSDIR}/lang/spidermonkey185

CONFLICTS_BUILD=spidermonkey17-1.7.*

USES=		gettext libtool gmake pathfix pkgconfig python:build \
		shebangfix
USE_GNOME=	cairo glib20 gnomeprefix introspection:build \
		intlhack
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--enable-compile-warnings=no

SHEBANG_FILES=	scripts/make-tests
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
