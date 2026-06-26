PORTNAME=	PyHive
DISTVERSION=	0.7.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python interface to Hive and Presto
WWW=		https://github.com/dropbox/PyHive

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thrift>=0.10.0:devel/py-thrift@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

OPTIONS_DEFINE=		HIVE PRESTO SQLALCHEMY KERBEROS
OPTIONS_DEFAULT=	HIVE PRESTO SQLALCHEMY

HIVE_DESC=		Hive backend support (SASL transport)
HIVE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pure-sasl>=0.6.2:devel/py-pure-sasl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}thrift_sasl>=0.1.0:devel/py-thrift_sasl@${PY_FLAVOR}

PRESTO_DESC=		Presto/Trino backend support
PRESTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:www/py-requests@${PY_FLAVOR}

SQLALCHEMY_DESC=	SQLAlchemy dialect support
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.3.0:databases/py-sqlalchemy20@${PY_FLAVOR}

KERBEROS_DESC=		Kerberos authentication support
KERBEROS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.12.0:security/py-requests-kerberos@${PY_FLAVOR}

.include <bsd.port.mk>
