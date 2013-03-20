# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/gobject-introspection/Makefile,v 1.51 2013/02/18 22:07:40 kwm Exp $

PORTNAME=	gobject-introspection
PORTVERSION=	1.34.2
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

# we need cairo otherwise the generated Cairo gir is broken
BUILD_DEPENDS=	cairo-trace:${PORTSDIR}/graphics/cairo
LIB_DEPENDS=	ffi.6:${PORTSDIR}/devel/libffi

USES=		bison pathfix
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier glib20 ltverhack
USE_PKGCONFIG=	build
USE_PYTHON=	-2.7
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-tests

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

MAN1=		g-ir-compiler.1 g-ir-generate.1 g-ir-scanner.1

.include <bsd.port.mk>
