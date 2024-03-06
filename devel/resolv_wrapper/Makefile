PORTNAME=		resolv_wrapper
PORTVERSION=		1.1.5
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Wrapper for dns name resolving or dns faking
WWW=		https://cwrap.org/resolv_wrapper.html

LICENSE=		GPLv3

USES=			cmake
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

PLIST_FILES=		libdata/pkgconfig/resolv_wrapper.pc \
			lib/cmake/resolv_wrapper/resolv_wrapper-config-version.cmake \
			lib/cmake/resolv_wrapper/resolv_wrapper-config.cmake \
			lib/libresolv_wrapper.so.0.0.5 \
			lib/libresolv_wrapper.so.0 \
			lib/libresolv_wrapper.so \
			share/man/man1/resolv_wrapper.1.gz

.include <bsd.port.mk>
