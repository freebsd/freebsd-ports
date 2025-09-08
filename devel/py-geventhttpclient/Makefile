PORTNAME=	geventhttpclient
PORTVERSION=	2.3.5
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Http client library for gevent
WWW=		https://github.com/geventhttpclient/geventhttpclient

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_TUPLE=	nodejs:llhttp:release/v6.0.11:nodejs_llhttp/llhttp

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/pyproject.toml ${WRKSRC}/src/geventhttpclient/__init__.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
