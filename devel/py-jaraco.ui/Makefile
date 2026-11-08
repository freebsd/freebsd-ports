PORTNAME=	jaraco.ui
PORTVERSION=	2.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jaraco_ui-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	User-Interface tools (mainly command-line)
WWW=		https://github.com/jaraco/jaraco.ui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.classes>=0:devel/py-jaraco.classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.text>=0:devel/py-jaraco.text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}named>=0:devel/py-named@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
