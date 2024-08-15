PORTNAME=	alembic
DISTVERSION=	1.13.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Database migration tool for SQLAlchemy
WWW=		https://alembic.zzzcomputing.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.3.0:databases/py-sqlalchemy14@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py*-alembic* # lib/python3.8/site-packages/alembic/__init__.py'

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/tox -e ${PY_FLAVOR}

.include <bsd.port.mk>
