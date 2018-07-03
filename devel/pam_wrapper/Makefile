# $FreeBSD$

PORTNAME=		pam_wrapper
PORTVERSION=		1.0.6
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Preloadable wrapper to test PAM applications and PAM Modules

LICENSE=		GPLv3

USES=			cmake:outsource python:2.7+
USE_LDCONFIG=		yes

CMAKE_ARGS+=		-DMAN_INSTALL_DIR:PATH="${PREFIX}/man"

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TARGET=		test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS+=	cmocka>=1.1.1:sysutils/cmocka

PLIST_FILES=		libdata/pkgconfig/pam_wrapper.pc \
			libdata/pkgconfig/libpamtest.pc \
			lib/cmake/pam_wrapper/pam_wrapper-config-version.cmake \
			lib/cmake/pam_wrapper/pam_wrapper-config.cmake \
			lib/cmake/libpamtest/libpamtest-config.cmake \
			lib/cmake/libpamtest/libpamtest-config-version.cmake \
			lib/libpam_wrapper.so.0.0.3 \
			lib/libpam_wrapper.so.0 \
			lib/libpam_wrapper.so \
			lib/libpamtest.so.0.0.3 \
			lib/libpamtest.so.0 \
			lib/libpamtest.so \
			lib/pam_wrapper/pam_matrix.so \
			lib/pam_wrapper/pam_get_items.so \
			lib/pam_wrapper/pam_set_items.so \
			${PYTHON_SITELIBDIR}/pypamtest.so \
			include/libpamtest.h \
			man/man1/pam_wrapper.1.gz \
			man/man8/pam_matrix.8.gz \
			man/man8/pam_get_items.8.gz \
			man/man8/pam_set_items.8.gz

.include <bsd.port.mk>
