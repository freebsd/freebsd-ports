# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/pygobject3-common/Makefile 19685 2014-05-25 13:11:28Z kwm $

PORTNAME=	gobject
PORTVERSION=	3.8.1
PORTREVISION?=	0
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
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

# this port doesn't work with py-gobject < 2.28.6_2, clungle below
CONFLICTS=	py*-gtk-0* py*-gobject-2.*.[0-6] py*-gobject-2.*.[7-9] \
		py*-gobject-2.*.6_1

PLIST_SUB=	ARCH=${ARCH} UNAME_R=${UNAME_R} VERSION=${PORTVERSION} \
		OPSYS=${OPSYS:tl} PYTHON_VER=${PYTHON_VER}

.if ${SLAVE_PORT} == no
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
USE_PYTHON_BUILD=	2
USE_GNOME=	glib20:build introspection:build
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pygobject-3.0/
	${INSTALL_DATA} ${WRKSRC}/gi/_gobject/pygobject.h \
		${STAGEDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_DATA} ${WRKSRC}/pygobject-3.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
.else 
USE_GNOME+=	glib20 introspection
LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi
RUN_DEPENDS+=	pygobject3-common>=0:${PORTSDIR}/devel/pygobject3-common

.if ${SLAVE_PORT} == python2
USE_PYTHON=	2
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
.endif

.if ${SLAVE_PORT} == python3
USE_PYTHON=	3
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/py3cairo.pc:${PORTSDIR}/graphics/py3-cairo
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/py3cairo.pc:${PORTSDIR}/graphics/py3-cairo
PLIST_SUB+=	PYTVER=${PYTHON_VER:S/.//}
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gi/*.so
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/pygobject-3.0 \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
.endif

.include <bsd.port.pre.mk>

UNAME_R!=	${UNAME} -r

.include <bsd.port.post.mk>
