PORTNAME=	seqwish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.10
CATEGORIES=	biology
MASTER_SITES=	https://github.com/ekg/seqwish/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment to variation graph inducer
WWW=		https://github.com/ekg/seqwish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: error: use of undeclared identifier '_pdep_u64'

USES=		cmake:noninja

#CMAKE_ARGS=	-DEXTRA_FLAGS="" # disable -march=native ; this causes the link failure: undefined symbol: __sync_val_compare_and_swap_16, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274927

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_CXXFLAGS=	-fopenmp
OPENMP_BROKEN_OFF=	https://github.com/ekg/seqwish/issues/114

.include <bsd.port.mk>
