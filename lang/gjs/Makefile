# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/lang/gjs/Makefile 18581 2013-06-23 10:50:00Z kwm $

PORTNAME=	gjs
PORTVERSION=	1.34.0
PORTREVISION=	2
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs185.so:${PORTSDIR}/lang/spidermonkey185

CONFLICTS_BUILD=spidermonkey17-1.7.*

USES=		gettext gmake libtool:keepla pathfix pkgconfig shebangfix tar:xz
USE_PYTHON_BUILD=2
USE_GNOME=	cairo glib20 gnomeprefix introspection:build intlhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	scripts/make-tests

.include <bsd.port.mk>
