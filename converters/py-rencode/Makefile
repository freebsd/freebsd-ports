PORTNAME=	rencode
PORTVERSION=	1.0.8
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	converters devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web safe object pickling/unpickling
WWW=		https://github.com/aresch/rencode

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist cython pep517 pytest

CPE_VENDOR=	rencode_project

USE_GITHUB=	yes
GH_ACCOUNT=	aresch

post-patch:
	@${MV} ${WRKSRC}/build.py ${WRKSRC}/_build.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
