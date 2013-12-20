# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/py-gobject/Makefile 18965 2013-12-20 11:02:42Z kwm $

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

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 introspection:build
USE_PYTHON=	2.5+
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-docs --disable-introspection

CONFLICTS=	py*-gtk-0*
PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"

post-install:
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PREFIX}/share/pygobject/2.0/codegen
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpyglib-2.0-${PYTHON_VERSION}.so.0
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/*/*/*.so

.include <bsd.port.mk>
