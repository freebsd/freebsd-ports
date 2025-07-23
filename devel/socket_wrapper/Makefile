PORTNAME=	socket_wrapper
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library passing all socket communications through unix sockets
WWW=		https://cwrap.org/socket_wrapper.html \
		https://git.samba.org/?p=socket_wrapper.git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	cmocka>=1.1.6:sysutils/cmocka

USES=		cmake:testing pathfix

CMAKE_OFF=	HELGRIND_TESTING \
		PICKY_DEVELOPER \
		UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
