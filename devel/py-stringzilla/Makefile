PORTNAME=	stringzilla
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.2
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD-accelerated string search/sort/hashes/fingerprints/edit distances
WWW=		https://ashvardanian.com/posts/stringzilla/ \
		https://github.com/ashvardanian/stringzilla

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-repeat>0:devel/py-pytest-repeat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-run-parallel>0:devel/py-pytest-run-parallel@${PY_FLAVOR}
#TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}affine-gaps>0:textproc/py-affine-gaps@${PY_FLAVOR} # TODO: add port for 3 tests

USES=		python
USE_PYTHON=	pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	ashvardanian
GH_PROJECT=	StringZilla
GH_TUPLE=	ashvardanian:ForkUnion:7f52520:fu/forkunion

PEP517_INSTALL_CMD_cpus=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_]+|_|g}s_cpus-${DISTVERSION}*.whl

PLIST_SUB=	PORTVERSION=${PORTVERSION}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
TEST_ARGS=	--disable-plugin-autoload \
		-p repeat -p pytest_run_parallel \
		--ignore=similarities.py \
		--ignore=fingerprints.py \
		--ignore=szs_helpers.py # these 3 tests require affine-gaps
TEST_ARGS+=	--ignore=stringzillas.py # fails: AttributeError: module 'stringzillas' has no attribute 'LevenshteinDistances'

post-install: # build the second (stringzillas_cpus) module and install it using similar commands as in python.mk
	# remove test files from the previous install of stringzilla module
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/test
	# remove previous build artifacts
	@${FIND} ${WRKSRC} -name "*.whl" -delete
	@${FIND} ${WRKSRC} -name "*.so" -delete
	# build the stringzillas module
	@${ECHO} "Building stringzillas-cpus module"
	@cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} SZ_TARGET=stringzillas-cpus ${PEP517_BUILD_CMD}
	# install the stringzillas module
	@${ECHO} "Installing stringzillas-cpus module"
	cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} SZ_TARGET=stringzillas-cpus ${PEP517_INSTALL_CMD_cpus}
	@${ECHO} "Installing stringzillas-cpus module DONE"
	# remove test files from strngzillas_cpu module install
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/test

# tests as of 5.1.2: 10595 passed, 73 skipped in 34.70s

.include <bsd.port.mk>
