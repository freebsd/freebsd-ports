PORTNAME=	seqwish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.11
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	https://github.com/ekg/seqwish/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment to variation graph inducer
WWW=		https://github.com/ekg/seqwish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	compilation fails: undefined symbol: __sync_val_compare_and_swap_16 ... referenced by transclosure.cpp
BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/ekg/seqwish/issues/126
BROKEN_i386=	compilation fails: error: use of undeclared identifier '_pdep_u64'

USES=		cmake:noninja compiler:c++14-lang

CMAKE_ARGS=	-DEXTRA_FLAGS="" # disable -march=native

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_CXXFLAGS=	-fopenmp
OPENMP_BROKEN_OFF=	https://github.com/ekg/seqwish/issues/114

.include <bsd.port.mk>
