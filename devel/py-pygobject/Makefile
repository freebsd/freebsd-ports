PORTNAME=	pygobject
DISTVERSION=	3.54.5
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

USES=		gnome pkgconfig python

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

OPTIONS_DEFINE=	TEST

TEST_TEST_DEPENDS=	bash:shells/bash
TEST_USE=	python=pytest
# PYTEST_BROKEN_TESTS may have infinite loops
# test_subprocess_communicate_stdout has caused kernel panics
TEST_VARS=	PEP517_BUILD_CONFIG_SETTING="-Csetup-args=-Dtests=true -Cbuild-dir=_build" \
		TEST_ARGS=--import-mode=importlib \
		PYTEST_BROKEN_TESTS="test_pytest_capture_error_in_closure test_sigint test_finalize test_idle_data test_idle_method_callback_no_data test_idle_method_callback_with_data test_idle_multidata test_idle_no_data" \
		PYTEST_IGNORED_TESTS=test_subprocess_communicate_stdout

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools<74|setuptools|' \
		${WRKSRC}/pyproject.toml

post-patch-TEST-on:
	@${REINPLACE_CMD} -e 's|"-Dtests=false", ||' \
		${WRKSRC}/pyproject.toml

pre-test-TEST-on:
	${CP} -a ${WRKSRC}/_build/ ${WRKSRC}
.endif

.include <bsd.port.mk>
