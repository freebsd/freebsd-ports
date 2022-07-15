PORTNAME=	aioftp
PORTVERSION=	0.21.3
CATEGORIES=	ftp python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	FTP client/server for asyncio

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/license.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest4-asyncio>=0:devel/py-pytest4-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest4-cov>=0:devel/py-pytest4-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trustme>=0:security/py-trustme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}siosocks>0:net/py-siosocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR}

USES=		python:3.7+ pytest:4
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
