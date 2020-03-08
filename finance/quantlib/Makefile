# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	quantlib
PORTVERSION=	1.17
PORTREVISION=	1
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
OPTIONS_SUB=	please

OPTIONS_DEFAULT=OPENMP EXAMPLES BENCHMARK UNITY_BUILD NEGATIVE_RATES

OPTIONS_DEFINE=	TRACING INDEXED_COUPONS
OPTIONS_DEFINE+=EXTRA_SAFETY_CHECKS SESSIONS INTRADAY
OPTIONS_DEFINE+=THREAD_SAFE_OBSERVER_PATTERN
OPTIONS_DEFINE+=THREAD_SAFE_SINGLETON_INIT
OPTIONS_DEFINE+=${OPTIONS_DEFAULT}

BENCHMARK_DESC=		Install benchmark (it is always built)
EXTRA_SAFETY_CHECKS_DESC=Trade performance for run-time checks
INDEXED_COUPONS_DESC=	Use indexed rather than par coupons
INTRADAY_DESC=		Time precision of msecs, instead of days
NEGATIVE_RATES_DESC=	Allow rates to be negative
TRACING_DESC=		Trade performance for more detailed errors
UNITY_BUILD_DESC=	Combine sources into one before compiling
SESSIONS_DESC=		See help

EXAMPLES_CONFIGURE_WITH=lispdir=${EXAMPLESDIR}
CONFIGURE_ARGS+=	--enable-parallel-unit-test-runner
CONFIGURE_ARGS+=	--with-boost-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-boost-lib=${LOCALBASE}/lib

.for o in ${OPTIONS_DEFINE}
$o_CONFIGURE_ENABLE=	${o:S/_/-/g:tl}
.endfor

CXXFLAGS_i386=	-DBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS

.include <bsd.port.mk>
