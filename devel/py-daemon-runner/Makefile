PORTNAME=	daemon-runner
PORTVERSION=	0.0.15
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Simple command line runner on top of python-daemon
WWW=		https://pypi.org/project/daemon-runner/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}daemon>0:devel/py-daemon@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
