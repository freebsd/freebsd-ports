# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	quantlib
PORTVERSION=	1.20
CATEGORIES=	finance math devel
MASTER_SITES=	https://dl.bintray.com/${PORTNAME}/releases/
DISTNAME=	QuantLib-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	C++ library for quantitative finance

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lang libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=no
MAKE_ENV+=	AM_MAKEFLAGS=${_MAKE_JOBS}
TEST_TARGET=	check-examples check
TEST_ARGS+=	-j1	# Tests use OpenMP - do not parallelize them
TEST_ENV+=	OMP_NUM_THREADS=${MAKE_JOBS_NUMBER}
OPTIONS_SUB=	please

OPTIONS_DEFAULT=OPENMP EXAMPLES BENCHMARK

OPTIONS_DEFINE=	TRACING INDEXED_COUPONS
OPTIONS_DEFINE+=EXTRA_SAFETY_CHECKS SESSIONS INTRADAY
OPTIONS_DEFINE+=THREAD_SAFE_OBSERVER_PATTERN
OPTIONS_DEFINE+=THREAD_SAFE_SINGLETON_INIT
OPTIONS_DEFINE+=${OPTIONS_DEFAULT}

BENCHMARK_DESC=		Install benchmark (it is always built)
EXTRA_SAFETY_CHECKS_DESC=Trade performance for run-time checks
INDEXED_COUPONS_DESC=	Use indexed rather than par coupons
INTRADAY_DESC=		Time precision of msecs, instead of days
TRACING_DESC=		Trade performance for more detailed errors
SESSIONS_DESC=		See help

EXAMPLES_CONFIGURE_WITH=lispdir=${EXAMPLESDIR}
CONFIGURE_ARGS+=	--disable-unity-build
CONFIGURE_ARGS+=	--enable-parallel-unit-test-runner
CONFIGURE_ARGS+=	--with-boost-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-boost-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-std-classes # Prefer C++11 to Boost

.for o in ${OPTIONS_DEFINE}
$o_CONFIGURE_ENABLE=	${o:S/_/-/g:tl}
.endfor

CXXFLAGS_i386=	-DBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS

.include <bsd.port.mk>
