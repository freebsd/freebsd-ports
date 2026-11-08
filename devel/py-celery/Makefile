PORTNAME=	celery
PORTVERSION=	5.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Asynchronous task queue/job queue
WWW=		https://pypi.org/project/celery/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}billiard>=4.2.1,<5.0:devel/py-billiard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.2,<9.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-didyoumean>=0.3.0:devel/py-click-didyoumean@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>=1.1.1:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-repl>=0.2.0:devel/py-click-repl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kombu>=5.6.0:net/py-kombu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vine>=5.1.0,<6.0:devel/py-vine@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python
CPE_VENDOR=	${PORTNAME}project
USE_PYTHON=	autoplist pep517

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}exceptiongroup>=1.3.0:devel/py-exceptiongroup@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
