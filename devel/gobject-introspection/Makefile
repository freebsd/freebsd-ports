# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/gobject-introspection/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	gobject-introspection
PORTVERSION=	1.36.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

# we need cairo otherwise the generated Cairo gir is broken
BUILD_DEPENDS=	cairo-trace:${PORTSDIR}/graphics/cairo
LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi

USES=		bison gettext gmake pathfix pkgconfig
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehier glib20 ltverhack
USE_PYTHON=	-2.7
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

MAN1=		g-ir-compiler.1 g-ir-generate.1 g-ir-scanner.1

post-patch:
	@${REINPLACE_CMD} -e 's|'gcc'|'cc'|g' \
		${WRKSRC}/giscanner/dumper.py

.include <bsd.port.mk>
