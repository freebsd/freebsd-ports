PORTNAME=	rencode
PORTVERSION=	1.0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	converters devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web safe object pickling/unpickling
WWW=		https://github.com/aresch/rencode

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist cython pep517 pytest

CPE_VENDOR=	rencode_project

USE_GITHUB=	yes
GH_ACCOUNT=	aresch

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
