PORTNAME=		pam_wrapper
PORTVERSION=		1.0.6
PORTREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Preloadable wrapper to test PAM applications and PAM Modules
WWW=		https://cwrap.org/pam_wrapper.html

LICENSE=		GPLv3

EXTRA_PATCHES=		${PATCHDIR}/python-detection.patch:-p1

USES=			cmake python
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

.include <bsd.port.mk>
