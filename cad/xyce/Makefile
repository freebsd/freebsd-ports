PORTNAME=	xyce
DISTVERSIONPREFIX=	Release-
DISTVERSION=	7.10.0
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Xyce electronic simulator
WWW=		https://xyce.sandia.gov/

LICENSE=	GPLv3
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
TEST_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		git:devel/git \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		autoreconf bison gmake fortran libtool localbase perl5 python:test # GNU tools should be used for 7.5 and on until the cmake build is declared stable
USE_CXXSTD=	c++14 # otherwise configure fails because of c++14 features like std::conditional_t
USE_CXXSTD=	c++17 # workaround for https://github.com/Xyce/Xyce/issues/97, which occurred when Trilinos was updated to 15.1.0
USE_LDCONFIG=	yes
USE_PERL5=	test

USE_GITHUB=	yes
GH_ACCOUNT=	Xyce
GH_PROJECT=	Xyce

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LEX=/usr/bin/flex \
		--enable-stokhos \
		--enable-amesos \
		--enable-shared \
		--disable-static
CFLAGS+=	-I${LOCALBASE}/include/kokkos # https://github.com/Xyce/Xyce/issues/137
CXXFLAGS+=	-I${LOCALBASE}/include/kokkos # https://github.com/Xyce/Xyce/issues/137

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	python=${PYTHON_CMD} # only for tests

do-test: # one test is known to fail, see https://github.com/Xyce/Xyce/issues/67#issuecomment-1179857728
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
# Xyce regression suite instructions: https://xyce.sandia.gov/documentation-tutorials/running-the-xyce-regression-suite/
# docs are in https://xyce.sandia.gov/files/xyce/Xyce_Docs-7.5.tar.gz

# tests as of 7.10.0:
# All Test runs complete - Warning 1 Tests FAILED (CommandLine/command_line.........................................TIME LIMIT[sh])
#                                  0 Tests EXITED WITH ERROR
# 				 Total testing time: 159.1m (wall),  8997s (user),   382s (system)

.include <bsd.port.mk>
