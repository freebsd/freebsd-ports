PORTNAME=		socket_wrapper
PORTVERSION=		1.4.2
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Library passing all socket communications through unix sockets
WWW=			https://cwrap.org/socket_wrapper.html

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			cmake pathfix
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		TEST

TEST_BUILD_DEPENDS=	cmocka>=1.1.5:sysutils/cmocka
TEST_USES=		localbase:ldflags pkgconfig
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
