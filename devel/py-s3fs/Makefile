PORTNAME=	s3fs
PORTVERSION=	2023.9.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convenient Filesystem interface over S3
WWW=		https://s3fs.readthedocs.io/en/latest/ \
		https://github.com/fsspec/s3fs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiobotocore>=2.5.4:devel/py-aiobotocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.9.1:devel/py-fsspec@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
