PORTNAME=	snowflake-connector-python
DISTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snowflake_connector_python-${DISTVERSION}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Snowflake Connector for Python
WWW=		https://github.com/snowflakedb/snowflake-connector-python

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.6.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>0.24.0<2.0.0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=22.0.0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt<3.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2<4:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5<4.0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3<5.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.5<4.0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.4.0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.6.0<5.0.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>0:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography cython3 pep517

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/snowflake/connector/nanoarrow_arrow_iterator.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
