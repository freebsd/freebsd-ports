PORTNAME=	bolt-lmm
DISTVERSION=	2.3.6
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	https://data.broadinstitute.org/alkesgroup/BOLT-LMM/downloads/
DISTNAME=	BOLT-LMM_v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Mixed model association testing and variance component analysis
WWW=		https://data.broadinstitute.org/alkesgroup/BOLT-LMM/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libnlopt.so:math/nlopt \
		libopenblas.so:math/openblas \
		libboost_program_options.so:devel/boost-libs

USES=		gmake

BUILD_WRKSRC=		${WRKDIR}/${DISTNAME}/src
INSTALL_WRKSRC=		${WRKDIR}/${DISTNAME}/src
CXXFLAGS_i386=		-DUSE_SSE -msse -msse2
CXXFLAGS_amd64=		-DUSE_SSE
MAKE_ARGS=		BOOST_INSTALL_DIR=${LOCALBASE} \
			NLOPT_INSTALL_DIR=${LOCALBASE} \
			ZLIB_STATIC_DIR=/usr/lib \
			LIBSTDCXX_STATIC_DIR=/usr/lib \
			GLIBC_STATIC_DIR=/usr/lib \
			SSEFLAGS="" \
			MEMCPY="" \
			LLAPACK="-lopenblas"

CONFLICTS_INSTALL=	rubygem-bolt # bin/bolt

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	@${RM} ${WRKSRC}/example/*.orig ${WRKSRC}/bolt
	@${REINPLACE_CMD} -e 's|tables/|${DATADIR}/tables/|g' \
		${BUILD_WRKSRC}/BoltParams.cpp
	@${REINPLACE_CMD} -e 's|../tables/|${DATADIR}/tables/|g' \
		${WRKSRC}/example/run_example.sh

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bolt ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} tables ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
