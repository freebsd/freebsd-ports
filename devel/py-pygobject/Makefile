PORTNAME=	pygobject
DISTVERSION=	3.50.2
PORTREVISION?=	0
CATEGORIES=	devel python
MASTER_SITES=	GNOME
PKGNAMEPREFIX?=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	Python bindings for GObject Introspection
WWW=		https://pygobject.gnome.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.16:graphics/py-cairo@${PY_FLAVOR}
LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gnome pkgconfig python:3.9+

BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTSCOUT=	limitw:1,even

SLAVE_PORT?=	no

.if ${SLAVE_PORT} == common
USES+=		meson
USE_GNOME=	glib20:build introspection:build

do-install:
	${INSTALL_DATA} ${WRKSRC}/_build/pygobject-3.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/pygobject-3.0.pc
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pygobject-3.0
	${INSTALL_DATA} ${WRKSRC}/gi/pygobject.h \
		${STAGEDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
.else
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.12.1:devel/meson-python@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.16:graphics/py-cairo@${PY_FLAVOR} \
		${LOCALBASE}/libdata/pkgconfig/pygobject-3.0.pc:devel/pygobject-common
USE_GNOME=	cairo glib20 introspection
USE_PYTHON=	autoplist concurrent pep517
.endif

.include <bsd.port.mk>
