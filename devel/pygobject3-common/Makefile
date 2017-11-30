# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gobject
PORTVERSION=	3.18.2
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	GNOME/sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX?=	py
PKGNAMESUFFIX?=	3-common
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common files for the Python bindings for GObject

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

SLAVE_PORT?=	no

USES=		gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

# this port doesn't work with py-gobject < 2.28.6_2, clungle below
CONFLICTS=	py*-gtk-0* py*-gobject-2.*.[0-6] py*-gobject-2.*.[7-9] \
		py*-gobject-2.*.6_1

PLIST_SUB=	ARCH=${ARCH} UNAME_R=${UNAME_R} VERSION=${PORTVERSION} \
		OPSYS=${OPSYS:tl} UNAME_M=${UNAME_M}

# Override PYTHON_VERSION from DEPENDS_ARGS
MAKE_ARGS=	PYTHON_VERSION=${PYTHON_VER}

.if ${SLAVE_PORT} == no
PORTSCOUT?=	limitw:1,even

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:graphics/py-cairo
USES+=		gnome python:build
USE_GNOME=	glib20:build introspection:build
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pygobject-3.0/
	${INSTALL_DATA} ${WRKSRC}/gi/pygobject.h \
		${STAGEDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_DATA} ${WRKSRC}/pygobject-3.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
.else
PORTSCOUT=	ignore:1

USES+=		gnome
USE_GNOME+=	glib20 introspection
LIB_DEPENDS+=	libffi.so:devel/libffi
RUN_DEPENDS+=	pygobject3-common>=0:devel/pygobject3-common

.if ${SLAVE_PORT} == python
USES+=		python
USE_PYTHON=	flavors
.if ${FLAVOR:Upy27:Mpy2*}
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:graphics/py-cairo@${PY_FLAVOR}
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:graphics/py-cairo@${PY_FLAVOR}
.else
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/py3cairo.pc:graphics/py-cairo@${PY_FLAVOR}
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/py3cairo.pc:graphics/py-cairo@${PY_FLAVOR}
.endif
.endif

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include/pygobject-3.0 \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
.endif

.include <bsd.port.pre.mk>

UNAME_R!=	${UNAME} -r
UNAME_M!=	${UNAME} -m

.include <bsd.port.post.mk>
