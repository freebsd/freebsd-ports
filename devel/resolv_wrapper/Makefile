PORTNAME=		resolv_wrapper
PORTVERSION=		1.1.8
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Wrapper for dns name resolving or dns faking
WWW=			https://cwrap.org/resolv_wrapper.html

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libsocket_wrapper.so:devel/socket_wrapper

USES=			cmake pathfix
USE_LDCONFIG=		yes

CMAKE_ARGS=		-DMAN_INSTALL_DIR:PATH="${PREFIX}/man"

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_BUILD_DEPENDS=	cmocka>=1.1.5:sysutils/cmocka
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
