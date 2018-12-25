# $FreeBSD$

PORTNAME=		pam_wrapper
PORTVERSION=		1.0.6
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Preloadable wrapper to test PAM applications and PAM Modules

LICENSE=		GPLv3

EXTRA_PATCHES=		${PATCHDIR}/python-detection.patch:-p1

USES=			cmake python:2.7+
USE_LDCONFIG=		yes

CMAKE_ARGS=		-DMAN_INSTALL_DIR:PATH="${PREFIX}/man"

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

.include <bsd.port.mk>
