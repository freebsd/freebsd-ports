PORTNAME=	corrosion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy Rust and C/C++ integration
WWW=		https://corrosion-rs.github.io/corrosion/ \
		https://github.com/corrosion-rs/corrosion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rustc:lang/rust
RUN_DEPENDS=	rustc:lang/rust

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	corrosion-rs

PLIST_FILES=	lib/cmake/Corrosion/CorrosionConfig.cmake \
		lib/cmake/Corrosion/CorrosionConfigVersion.cmake \
		share/cmake/Corrosion.cmake \
		share/cmake/CorrosionGenerator.cmake \
		share/cmake/FindRust.cmake

CMAKE_TESTING_ON=	CORROSION_BUILD_TESTS # 2 tests fail

NO_ARCH=	yes

# tests as of 0.5.2: 97% tests passed, 2 tests failed out of 72 (2 failures are in rustup and parsing of triplets)

.include <bsd.port.mk>
