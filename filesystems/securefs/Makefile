PORTNAME=	securefs
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Filesystem in userspace with transparent encryption and decryption
WWW=		https://github.com/netheril96/securefs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/include/tclap/TCLAPConfig.h:devel/tclap
LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libargon2.so:security/libargon2 \
		libcryptopp.so:security/cryptopp \
		libfruit.so:devel/fruit \
		libprotobuf.so:devel/protobuf \
		libuni-algo.so:textproc/uni-algo

USES=		cmake compiler:c++17-lang fuse pkgconfig sqlite

CMAKE_OFF=	SECUREFS_ADDRESS_SANITIZE \
		SECUREFS_ENABLE_INTEGRATION_TEST \
		SECUREFS_ENABLE_JEMALLOC \
		SECUREFS_ENABLE_MIMALLOC \
		SECUREFS_ENABLE_UNIT_TEST \
		SECUREFS_LINK_PROFILER \
		SECUREFS_USE_FUSET \
		SECUREFS_USE_VCPKG

PLIST_FILES=	bin/securefs

USE_GITHUB=	yes
GH_ACCOUNT=	netheril96

.include <bsd.port.mk>
