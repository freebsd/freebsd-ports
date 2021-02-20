# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gobject
PORTVERSION=	3.38.0
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	GNOME/sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX?=	py
PKGNAMESUFFIX?=	3-common
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	Common files for the Python bindings for GObject

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

SLAVE_PORT?=	no

USES=		meson pkgconfig tar:xz

# this port doesn't work with py-gobject < 2.28.6_2, clungle below
CONFLICTS=	py*-gtk-0* py*-gobject-2.*.[0-6] py*-gobject-2.*.[7-9] \
		py*-gobject-2.*.6_1

PLIST_SUB=	ARCH=${ARCH} UNAME_R=${UNAME_R} VERSION=${PORTVERSION} \
		OPSYS=${OPSYS:tl} UNAME_M=${UNAME_M}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.if ${SLAVE_PORT} == no
PORTSCOUT?=	limitw:1,even

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}
USES+=		gnome python:build
USE_GNOME=	glib20:build introspection:build
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pygobject-3.0/
	${INSTALL_DATA} ${WRKSRC}/gi/pygobject.h \
		${STAGEDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_DATA} ${WRKSRC}/_build/pygobject-3.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
.else
PORTSCOUT=	ignore:1

USES+=		gettext-runtime gnome
USE_GNOME+=	cairo glib20 introspection
LIB_DEPENDS+=	libffi.so:devel/libffi
RUN_DEPENDS+=	pygobject3-common>=0:devel/pygobject3-common

.  if ${SLAVE_PORT} == python
USES+=		python:3.6+
USE_PYTHON=	flavors py3kplist
MESON_ARGS+=	-Dpython=${PYTHON_VERSION}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}
.  endif

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include/pygobject-3.0 \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
.endif

.include <bsd.port.pre.mk>

UNAME_R!=	${UNAME} -r
UNAME_M!=	${UNAME} -m

.include <bsd.port.post.mk>
