PORTNAME=	xyce
DISTVERSION=	7.5.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/Xyce/Xyce/archive/refs/tags/
DISTNAME=	Release-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Xyce electronic simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack \
		libtpetra.so:science/trilinos \
		\
		libamd.so:math/suitesparse-amd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libsuitesparseconfig.so:math/suitesparse-config \
		libumfpack.so:math/suitesparse-umfpack
TEST_DEPENDS=	git:devel/git \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		# also needs pycompadre

USES=		autoreconf bison gmake fortran libtool localbase perl5 python:test # GNU tools should be used for 7.5 and on until the cmake cbuild is declared stable
USE_CXXSTD=	c++14 # otherwise configure fails because of c++14 features like std::conditional_t
USE_LDCONFIG=	yes
USE_PERL5=	test

WRKSRC=		${WRKDIR}/Xyce-Release-${DISTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LEX=/usr/bin/flex \
		--enable-stokhos \
		--enable-amesos \
		--enable-shared \
		--disable-static

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	python=${PYTHON_CMD} # only for tests

do-test:
	# checkout tests
	@cd ${WRKDIR} && \
		${ECHO} "cloning git repository ..." && \
		${RM} -rf Xyce_Regression && \
		git clone -q https://github.com/Xyce/Xyce_Regression.git && \
		cd Xyce_Regression && \
		git checkout -q Release-${DISTVERSION}

	# run tests
	@cd ${TEST_WRKSRC} && ( \
		${ECHO} "running tests ..."; \
		eval `${WRKDIR}/Xyce_Regression/TestScripts/suggestXyceTagList.sh ${STAGEDIR}${PREFIX}/bin/Xyce` ; \
		${SETENV} ${TEST_ENV} ${WRKDIR}/Xyce_Regression/TestScripts/run_xyce_regression \
			--output=${WRKDIR}/Xyce_Test \
			--xyce_test="${WRKDIR}/Xyce_Regression" \
			--resultfile=${WRKDIR}/serial_results \
			--taglist="$$TAGLIST" \
			${STAGEDIR}${PREFIX}/bin/Xyce \
	)
	# Testssuite doesn't stop when Ctrl-C is pressed: https://github.com/Xyce/Xyce_Regression/issues/1

# Trilinos build instructions for Xyce: https://xyce.sandia.gov/documentation-tutorials/building-guide/#instTrilinos
# Xyce build instructions: https://xyce.sandia.gov/documentation-tutorials/building-guide/
# docs are in https://xyce.sandia.gov/files/xyce/Xyce_Docs-7.5.tar.gz

.include <bsd.port.mk>
