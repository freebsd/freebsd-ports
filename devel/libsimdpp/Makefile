# $FreeBSD$

PORTNAME=	libsimdpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	e71d2ca2d445db627308167cd551d4934af5f4af.patch:-p1 # https://github.com/p12tic/libsimdpp/pull/129

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only zero-overhead C++ wrapper of SIMD instructions

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

PORTSCOUT=	limit:^[v1-9]

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	p12tic
NO_BUILD=	yes
NO_ARCH=	yes
TEST_TARGET=	check

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
