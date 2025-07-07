PORTNAME=		uid_wrapper
PORTVERSION=		1.2.4
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Wrapper to fake privilege separation
WWW=		https://cwrap.org/uid_wrapper.html

LICENSE=		GPLv3

USES=			cmake
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

PLIST_FILES=		libdata/pkgconfig/uid_wrapper.pc \
			lib/cmake/uid_wrapper/uid_wrapper-config-version.cmake \
			lib/cmake/uid_wrapper/uid_wrapper-config.cmake \
			lib/libuid_wrapper.so.0.0.6 \
			lib/libuid_wrapper.so.0 \
			lib/libuid_wrapper.so \
			share/man/man1/uid_wrapper.1.gz

.include <bsd.port.mk>
