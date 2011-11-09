# New ports collection makefile for:	py-gobject
# Date created:				10 January 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/py-gobject/Makefile,v 1.52 2011/06/13 20:37:47 kwm Exp $
#

PORTNAME=	gobject
PORTVERSION=	2.28.6
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_PYTHON=	2.5+
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-docs

CONFLICTS=	py*-gtk-0*
PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libffi.so)
LIB_DEPENDS+=	ffi.5:${PORTSDIR}/devel/libffi
CONFIGURE_ARGS+=--with-ffi
.else
CONFIGURE_ARGS+=--without-ffi
.endif

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/pygobject/2.0/codegen

.include <bsd.port.post.mk>
