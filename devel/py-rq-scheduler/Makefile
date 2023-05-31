PORTNAME=	rq-scheduler
PORTVERSION=	0.13.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide job scheduling capabilities to RQ (Redis Queue)
WWW=		https://github.com/rq/rq-scheduler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crontab>=0.23.0:devel/py-crontab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>=0.3.9:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=0.13:devel/py-rq@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	rq_scheduler/scripts/rqscheduler.py

.include <bsd.port.mk>
