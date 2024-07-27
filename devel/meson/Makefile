PORTNAME=	meson
PORTVERSION=	1.5.1
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/mesonbuild/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	High performance build system
WWW=		https://mesonbuild.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		ninja:run python shebangfix
USE_PYTHON=	autoplist pep517
SHEBANG_FILES=	mesonbuild/rewriter.py \
		mesonbuild/scripts/cmake_run_ctgt.py
NO_ARCH=	yes

# https://github.com/mesonbuild/meson/issues/6016
TEST_ENV=	${MAKE_ENV:NCC=*:NCXX=*}

# Hide from regular build to avoid accidental dependency on symlinks
.if make(test) || ("${WITH_TESTING}" == yes && make(package))
# helper_create_binary_wrapper, test_python_module, test cases/*.py
BINARY_ALIAS+=	python3=${PYTHON_CMD:T} python=${PYTHON_CMD:T}
do-test: create-binary-alias # force if run late
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
.endif

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/run_unittests.py)

.include <bsd.port.post.mk>
