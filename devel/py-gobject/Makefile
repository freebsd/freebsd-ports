# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/py-gobject/Makefile,v 1.58 2012/12/30 18:15:16 mezz Exp $

PORTNAME=	gobject
PORTVERSION=	2.28.6
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS+=	ffi:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

USES=		pathfix pkgconfig
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-docs --disable-introspection --with-ffi

CONFLICTS=	py*-gtk-0*
PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"

NO_STAGE=	yes
post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/pygobject/2.0/codegen

.include <bsd.port.mk>
