PORTNAME=	pip-run
PORTVERSION=	12.6.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Install packages and run Python with them
WWW=		https://github.com/jaraco/pip-run

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=56:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autocommand>=0:devel/py-autocommand@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>=0:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.env>=0:devel/py-jaraco.env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=3.7:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.text>=0:devel/py-jaraco.text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8.3:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path>=15.1:devel/py-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=19.3:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
