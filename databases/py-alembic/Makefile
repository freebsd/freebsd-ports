PORTNAME=	alembic
DISTVERSION=	1.15.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Database migration tool for SQLAlchemy
WWW=		https://alembic.zzzcomputing.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	py*-alembic* # lib/python3.8/site-packages/alembic/__init__.py'

NO_ARCH=	yes

OPTIONS_RADIO=	SQLALCHEMY
OPTIONS_RADIO_SQLALCHEMY=	SQLALCHEMY14 SQLALCHEMY20
OPTIONS_DEFAULT=	SQLALCHEMY20

SQLALCHEMY_DESC=	SQLAlchemy version
SQLALCHEMY14_DESC=	Install with SQLAlchemy 1.4
SQLALCHEMY20_DESC=	Install with SQLAlchemy 2.0

SQLALCHEMY14_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.0:databases/py-sqlalchemy14@${PY_FLAVOR}
SQLALCHEMY20_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.0:databases/py-sqlalchemy20@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/tox -e ${PY_FLAVOR}

.include <bsd.port.mk>
