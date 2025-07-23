PORTNAME=	priv_wrapper
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to disable resource limits and other privilege dropping
WWW=		https://cwrap.org/priv_wrapper.html \
		https://git.samba.org/?p=priv_wrapper.git

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	cmocka>=1.1.0:sysutils/cmocka

USES=		cmake:testing pathfix

CMAKE_OFF=	HELGRIND_TESTING \
		PICKY_DEVELOPER \
		UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
