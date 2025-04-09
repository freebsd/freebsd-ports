PORTNAME=	pip-check
PORTVERSION=	2.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pip_check-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DDisplay installed pip packages and their update status
WWW=		https://github.com/bartTC/pip-check

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=9:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminaltables>=0:textproc/py-terminaltables@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
