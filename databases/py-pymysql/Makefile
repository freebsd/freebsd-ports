PORTNAME=	pymysql
DISTVERSION=	1.1.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Pure Python MySQL Driver
WWW=		https://github.com/PyMySQL/PyMySQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

OPTIONS_DEFINE=	ED25519 RSA

ED25519_DESC=	MariaDB ed25519 auth method support
ED25519_LIB_DEPENDS_ON=	${PYTHON_PKGNAMEPREFIX}pynacl>=1.4.0:security/py-pynacl@${PY_FLAVOR}

RSA_DESC=	sha256_password or caching_sha2_password auth method support
RSA_LIB_DEPENDS_ON=${PYTHON_PKGNAMEPREFIX}pycryptography:security/py-cryptography@${PY_FLAVOR}

.include <bsd.port.mk>
