PORTNAME=	unarr
DISTVERSION=	1.2.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/selmf/unarr/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Decompression library for RAR, TAR, ZIP and 7z* archives
WWW=		https://github.com/selmf/unarr

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=		cmake:testing tar:xz
USE_LDCONFIG=	yes
CMAKE_TESTING_ON=	BUILD_INTEGRATION_TESTS BUILD_UNIT_TESTS

.include <bsd.port.mk>
