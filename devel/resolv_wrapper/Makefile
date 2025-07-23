PORTNAME=	resolv_wrapper
PORTVERSION=	1.1.8
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for DNS name resolving or DNS faking
WWW=		https://cwrap.org/resolv_wrapper.html \
		https://git.samba.org/?p=resolv_wrapper.git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsocket_wrapper.so:devel/socket_wrapper
TEST_DEPENDS=	cmocka>=1.1.5:sysutils/cmocka

USES=		cmake:testing pathfix

CMAKE_OFF=	UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
