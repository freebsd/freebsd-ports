# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gobject-introspection
PORTVERSION=	1.56.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL

# we need cairo otherwise the generated Cairo gir is broken
BUILD_DEPENDS=	cairo-trace:graphics/cairo
LIB_DEPENDS=	libffi.so:devel/libffi

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake gnome libtool localbase pathfix \
		pkgconfig python:3.4+ tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-doctool
INSTALL_TARGET=	install-strip

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

.include <bsd.port.mk>
