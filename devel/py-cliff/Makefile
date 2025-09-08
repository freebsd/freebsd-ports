PORTNAME=	cliff
PORTVERSION=	4.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command Line Interface Formulation Framework
WWW=		https://docs.openstack.org/cliff/latest/ \
		https://github.com/openstack/cliff

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=6.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autopage>=0.4.0:devel/py-autopage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmd2>=1.0.0:devel/py-cmd2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable0>=0.7.2:devel/py-prettytable0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.12:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=2.0.1:devel/py-stevedore@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
