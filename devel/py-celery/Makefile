PORTNAME=	celery
PORTVERSION=	5.3.6
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Asynchronous task queue/job queue
WWW=		https://pypi.org/project/celery/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}billiard>=4.1.0,<5.0:devel/py-billiard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-didyoumean>=0.3.0:devel/py-click-didyoumean@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>=1.1.1:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-repl>=0.3.0:devel/py-click-repl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=1.5:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kombu>=5.3.2,<6.0.0:net/py-kombu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vine>=1.3.0:devel/py-vine@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python
CPE_VENDOR=	${PORTNAME}project
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
