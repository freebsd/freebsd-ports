PORTNAME=	seqwish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.11
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	https://github.com/ekg/seqwish/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment to variation graph inducer
WWW=		https://github.com/ekg/seqwish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsdsl.so:devel/sdsl-lite

USES=		cmake:noninja compiler:c++14-lang pkgconfig

CMAKE_ARGS=	-DEXTRA_FLAGS="" # disable -march=native

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		OPENMP
.if exists(/usr/include/omp.h)
OPTIONS_DEFAULT=	OPENMP
.else
OPENMP_BROKEN=	OpenMP isn't available on this architecture
.endif

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_CXXFLAGS=	-fopenmp
OPENMP_BROKEN_OFF=	https://github.com/ekg/seqwish/issues/114

post-extract:
	@${RM} -r ${WRKSRC}/deps/sdsl-lite

.include <bsd.port.mk>
