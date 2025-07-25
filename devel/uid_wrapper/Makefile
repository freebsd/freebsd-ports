PORTNAME=	uid_wrapper
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing tool to fake privilege separation
WWW=		https://cwrap.org/uid_wrapper.html \
		https://git.samba.org/?p=uid_wrapper.git

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	cmocka>=1.1.0:sysutils/cmocka

USES=		cmake:testing localbase pathfix

CMAKE_OFF=	PICKY_DEVELOPER \
		UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
