PORTNAME=	jschon
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.1
CATEGORIES=	devel textproc python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON toolkit for Python developers
WWW=		https://github.com/marksparkza/jschon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rfc3986>0:www/py-rfc3986@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpserver>=0:devel/py-pytest-httpserver@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 4 tests fail, see https://github.com/marksparkza/jschon/issues/118

USE_GITHUB=	yes
GH_ACCOUNT=	marksparkza
GH_TUPLE=	json-schema-org:JSON-Schema-Test-Suite:0433a2bf827d3039c272e831049a6e58deab787d:json_schema_org_JSON_Schema_Test_Suite/tests/JSON-Schema-Test-Suite \
		json-schema-org:json-schema-spec:aaedf928fb5aba87d815d0a7a152e872b13cbb77:json_schema_org_json_schema_spec1/jschon/catalog/json-schema-2019-09 \
		json-schema-org:json-schema-spec:6b2052df656484d01bdf1969b709dc8845884678:json_schema_org_json_schema_spec2/jschon/catalog/json-schema-2020-12 \
		marksparkza:json-schema-spec:2cb7c7447f9b795c9940710bf0eda966a92c937f:marksparkza_json_schema_spec/jschon/catalog/json-schema-next

NO_ARCH=	yes

.include <bsd.port.mk>
