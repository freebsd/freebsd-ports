PORTNAME=	s3fs
PORTVERSION=	2025.7.0
CATEGORIES=	filesystems devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convenient Filesystem interface over S3
WWW=		https://s3fs.readthedocs.io/en/latest/ \
		https://github.com/fsspec/s3fs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiobotocore>=2.5.4<3.0.0:devel/py-aiobotocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=${PORTVERSION}<${PORTVERSION}_99:filesystems/py-fsspec@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AWSCLI BOTO3
AWSCLI_DESC=	Use awscli
BOTO3_DESC=	Use boto3

AWSCLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awscli>=1.29.17:devel/py-awscli@${PY_FLAVOR}
BOTO3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.28.17:www/py-boto3@${PY_FLAVOR}

.include <bsd.port.mk>
