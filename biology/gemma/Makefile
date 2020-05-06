# $FreeBSD$

PORTNAME=	gemma
DISTVERSION=	0.98.1
PORTREVISION=	5
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Efficient Mixed Model Association

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		blaslapack:openblas compiler:c++11-lang eigen:3 gmake \
		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	genetics-statistics
GH_PROJECT=	GEMMA

MAKEFILE=	${FILESDIR}/Makefile
# Assuming openblas is built with pthreads, not openmp
CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 -DOPENBLAS -pthread
LDFLAGS+=	-lopenblas -pthread

OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	@${REINPLACE_CMD} -e 's|../bin/gemma|../gemma|' ${WRKSRC}/test/*.sh

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-test:
	(cd ${WRKSRC}/test && ${SH} test_suite.sh)

.include <bsd.port.mk>
