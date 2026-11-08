PORTNAME=	prance
PORTVERSION=	26.7.19.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Resolve Swagger/OpenAPI 2.0 and 3.0.0 parser
WWW=		https://github.com/RonnyPfannschmidt/prance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=9:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=5.2,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.18.16:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI FAST ICU
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	FLEX OSV SSV
OPTIONS_DEFAULT=OSV
CLI_DESC=	Command-line interface support
FAST_DESC=	Fast deepcopy support
FLEX_DESC=	Use py-flex as backend
ICU_DESC=	Unicode support
OSV_DESC=	Use py-openapi-spec-validator as backend
SSV_DESC=	Use py-swagger-spec-validator as backend

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.3.0:devel/py-click@${PY_FLAVOR}
FLEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flex>=6.14.1<7:devel/py-flex@${PY_FLAVOR}
FAST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orjson>=3.9:devel/py-orjson@${PY_FLAVOR}
ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=2.14<3:devel/py-pyicu@${PY_FLAVOR}
OSV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>=0.7.1:devel/py-openapi-spec-validator@${PY_FLAVOR}
SSV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}swagger-spec-validator>=3.0.4<3.1:devel/py-swagger-spec-validator@${PY_FLAVOR}

.include <bsd.port.mk>
