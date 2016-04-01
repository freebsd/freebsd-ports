# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/py-gobject/Makefile,v 1.58 2012/12/30 18:15:16 mezz Exp $

PORTNAME=	gobject
PORTVERSION=	2.28.6
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	GNOME/sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:graphics/py-cairo
LIB_DEPENDS+=	libffi.so:devel/libffi
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:graphics/py-cairo

PORTSCOUT=	ignore:1

USES=		gmake libtool pathfix pkgconfig python:2 tar:xz
USE_GNOME=	glib20 introspection:build,run
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-docs --disable-introspection --with-ffi
INSTALL_TARGET=	install-strip

CONFLICTS=	py*-gtk-0*
PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"

PYSHAREDIR=	${PREFIX}/share/pygobject/2.0/codegen

post-install:
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYSHAREDIR} -f ${PYSHAREDIR:S;${PREFIX}/;;}
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYSHAREDIR} -f ${PYSHAREDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>
