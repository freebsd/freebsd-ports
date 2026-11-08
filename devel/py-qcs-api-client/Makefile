PORTNAME=	qcs-api-client
DISTVERSION=	0.27.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Client library for accessing the Rigetti QCS API
WWW=		https://github.com/rigetti/qcs-api-client-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.12.7:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=25.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=2.27.2:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.8.1:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10.6:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.12.1:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.9.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcs-api-client-common>=0.17.5:devel/py-qcs-api-client-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3339>=6.2:devel/py-rfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.1.4:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's/,<0.13"/"/' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
