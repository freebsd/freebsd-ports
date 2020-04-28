# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rq-scheduler
PORTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide job scheduling capabilities to RQ (Redis Queue)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}croniter>=0.3.9:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=0.13:devel/py-rq@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	rq_scheduler/scripts/rqscheduler.py

.include <bsd.port.mk>
