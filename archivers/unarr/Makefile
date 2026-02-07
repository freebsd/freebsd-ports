PORTNAME=	unarr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	archivers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decompression library for RAR, TAR, ZIP and 7z* archives
WWW=		https://github.com/selmf/unarr

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=		cmake:testing
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	selmf
CMAKE_TESTING_ON=	BUILD_INTEGRATION_TESTS BUILD_UNIT_TESTS

.include <bsd.port.mk>
