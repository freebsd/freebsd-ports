# $FreeBSD$

PORTNAME=	bencode.py
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	converters devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Bencoding and bdecoding implementation

LICENSE=	BTOSL
LICENSE_NAME=	BitTorrent Open Source License
LICENSE_TEXT=	See http://directory.fsf.org/wiki/License:BitTorrentOSL1.1
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.9:devel/py-pbr@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER})

.include <bsd.port.mk>
