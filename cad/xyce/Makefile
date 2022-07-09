PORTNAME=	xyce
DISTVERSION=	7.5
CATEGORIES=	cad
MASTER_SITES=	https://xyce.sandia.gov/files/xyce/
DISTNAME=	Xyce-${DISTVERSION}

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

USES=		bison cmake localbase

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} ${STAGEDIR}${PREFIX}/doc/README.TXT && \
		${RMDIR} ${STAGEDIR}${PREFIX}/doc

# Trilinos build instructions for Xyce: https://xyce.sandia.gov/documentation-tutorials/building-guide/#instTrilinos
# docs are in https://xyce.sandia.gov/files/xyce/Xyce_Docs-7.5.tar.gz

.include <bsd.port.mk>
