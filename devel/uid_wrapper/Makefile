PORTNAME=	uid_wrapper
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing tool to fake privilege separation
WWW=		https://cwrap.org/uid_wrapper.html \
		https://git.samba.org/?p=uid_wrapper.git

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

USES=		cmake pathfix

CMAKE_OFF=	UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
