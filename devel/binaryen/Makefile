# $FreeBSD$

PORTNAME=	binaryen
DISTVERSIONPREFIX=	version_
DISTVERSION=	93
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Compiler infrastructure and toolchain library for WebAssembly

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake python:3.6+,build compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBINARYEN_VERSION_INFO=${DISTVERSION}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
