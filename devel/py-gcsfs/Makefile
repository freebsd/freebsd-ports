PORTNAME=	gcsfs
PORTVERSION=	2023.9.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convenient Filesystem interface over GCS
WWW=		https://gcsfs.readthedocs.io/en/latest/ \
		https://github.com/fsspec/gcsfs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.1.2:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.9.1:devel/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>=0:security/py-google-auth-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.2:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=0:www/py-google-cloud-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
