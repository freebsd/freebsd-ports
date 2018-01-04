# $FreeBSD$

PORTNAME=	libfmt
PORTVERSION=	3.0.1
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	SlavaMikerov@gmail.com
COMMENT=	Fmt is an open-source formatting library for C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake:outsource compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	fmtlib
GH_PROJECT=	fmt
CMAKE_ARGS=	-DFMT_DOC=OFF -DBUILD_SHARED_LIBS=ON
OPTIONS_DEFINE=	TEST
TEST_CMAKE_BOOL=	FMT_TEST

.include <bsd.port.mk>
