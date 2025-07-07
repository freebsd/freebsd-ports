PORTNAME=		nss_wrapper
PORTVERSION=		1.1.3
PORTREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Wrapper for the user, group and hosts NSS API
WWW=		https://cwrap.org/nss_wrapper.html

LICENSE=		GPLv3

USES=			cmake compiler:c++11-lang perl5 shebangfix
USE_PERL5=		run
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

SHEBANG_FILES=		nss_wrapper.pl

PLIST_FILES=		bin/nss_wrapper.pl \
			libdata/pkgconfig/nss_wrapper.pc \
			lib/cmake/nss_wrapper/nss_wrapper-config-version.cmake \
			lib/cmake/nss_wrapper/nss_wrapper-config.cmake \
			lib/libnss_wrapper.so.0.2.3 \
			lib/libnss_wrapper.so.0 \
			lib/libnss_wrapper.so \
			share/man/man1/nss_wrapper.1.gz

.include <bsd.port.mk>
