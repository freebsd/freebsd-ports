PORTNAME=	xyce
DISTVERSION=	7.5.0
CATEGORIES=	cad
MASTER_SITES=	https://github.com/Xyce/Xyce/archive/refs/tags/
DISTNAME=	Release-${DISTVERSION}
DIST_SUBDIR=	xyce-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Xyce electronic simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack \
		libtpetra.so:science/trilinos \
		libumfpack.so:math/suitesparse-umfpack
TEST_DEPENDS=	git:devel/git

USES=		bison cmake localbase

CMAKE_ON=	BUILD_SHARED_LIBS

WRKSRC=		${WRKDIR}/Xyce-Release-${DISTVERSION}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} ${STAGEDIR}${PREFIX}/doc/README.TXT && \
		${RMDIR} ${STAGEDIR}${PREFIX}/doc

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
		${WRKDIR}/Xyce_Regression/TestScripts/run_xyce_regression \
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
