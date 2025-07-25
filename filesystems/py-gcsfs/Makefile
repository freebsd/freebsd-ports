PORTNAME=	gcsfs
PORTVERSION=	2025.7.0
CATEGORIES=	filesystems devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convenient Filesystem interface over GCS
WWW=		https://gcsfs.readthedocs.io/en/latest/ \
		https://github.com/fsspec/gcsfs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.1.2:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=${PORTVERSION}<${PORTVERSION}_99:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>=0:security/py-google-auth-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.2:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=0:www/py-google-cloud-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GCSFUSE CRC
GCSFUSE_DESC=	Fuse support
CRC_DESC=	CRC support

GCSFUSE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crcmod>=0:devel/py-crcmod@${PY_FLAVOR}
CRC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fusepy>=0:filesystems/py-fusepy@${PY_FLAVOR}

.include <bsd.port.mk>
