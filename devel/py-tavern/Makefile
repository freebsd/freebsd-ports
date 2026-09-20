PORTNAME=	tavern
DISTVERSION=	3.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lazeraman@gmail.com
COMMENT=	Command-line tool and pytest plugin for testing RESTful APIs
WWW=		https://github.com/taverntesting/tavern

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jmespath>=1:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.5.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykwalify>=1.8.0:textproc/py-pykwalify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-box>=6:devel/py-python-box@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simpleeval>=1.0.3:devel/py-simpleeval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=4:devel/py-stevedore@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GRAPHQL GRPC MQTT
GRAPHQL_DESC=	Enables GraphQL support
GRPC_DESC=	Enables gRPC support
MQTT_DESC=	Enables MQTT support

GRAPHQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gql>=4.0.0:devel/py-gql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websockets>=0:devel/py-websockets@${PY_FLAVOR}
GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=0:www/py-google-api-python-client@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio-reflection>=0:devel/py-grpcio-reflection@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio-status>=0:devel/py-grpcio-status@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio>=0:devel/py-grpcio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}proto-plus>=0:devel/py-proto-plus@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}protobuf>=5:devel/py-protobuf@${PY_FLAVOR}
MQTT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paho-mqtt>=1.3.1:net/py-paho-mqtt@${PY_FLAVOR}

.include <bsd.port.mk>
