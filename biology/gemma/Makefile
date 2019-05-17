# $FreeBSD$

PORTNAME=	GEMMA
DISTVERSION=	0.98.1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Efficient Mixed Model Association

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcblas.so:math/cblas \
		libgsl.so:math/gsl

USES=		blaslapack:openblas compiler:c++11-lang eigen:3 gmake \
		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	genetics-statistics

MAKEFILE=	${FILESDIR}/Makefile
CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 -DOPENBLAS -DOPENBLAS_LEGACY
LDFLAGS+=	-lopenblas

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

# Force newer GCC on platforms using GCC 4.2 as base
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|../bin/gemma|../gemma|' ${WRKSRC}/test/*.sh

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-test:
	(cd ${WRKSRC}/test && ${SH} test_suite.sh)

.include <bsd.port.post.mk>
