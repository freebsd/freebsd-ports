# Created by: Ting-Wei Lan <lantw44@gmail.com>
# $FreeBSD$

PORTNAME=	meson
PORTVERSION=	0.52.1
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/mesonbuild/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High performance build system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ninja:devel/ninja
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python:3.5+ shebangfix
USE_PYTHON=	autoplist distutils noflavors
SHEBANG_FILES=	mesonbuild/cmake/data/run_ctgt.py
NO_ARCH=	yes

# https://github.com/mesonbuild/meson/issues/6016
TEST_ENV=	${MAKE_ENV:NCC=*:NCXX=*}

# Hide from regular build to avoid accidental dependency on symlinks
.if make(test)
# helper_create_binary_wrapper, test_python_module, test cases/*.py
BINARY_ALIAS+=	python3=${PYTHON_CMD:T} python=${PYTHON_CMD:T}
do-test: create-binary-alias # force if run late
.endif

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/run_unittests.py)

.include <bsd.port.mk>
