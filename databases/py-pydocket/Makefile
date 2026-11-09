PORTNAME=	pydocket
DISTVERSION=	0.28.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed background task system for Python functions
WWW=		https://docket.lol/ \
		https://github.com/chrisguidry/docket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}burner-redis>=0.1.7:databases/py-burner-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=3.1.1:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cronsim>=2.6:devel/py-cronsim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.21.1:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-key-value-aio>=0.3.0:devel/py-py-key-value-aio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-json-logger>=2.0.7:devel/py-python-json-logger@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=6:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.9.4:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.15.1:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncalled-for>=0.6.0:devel/py-uncalled-for@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
