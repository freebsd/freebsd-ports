PORTNAME=	cython-lint
PORTVERSION=	0.16.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/MarcoGorelli/cython-lint/releases/download/v${PORTVERSION}/
DISTNAME=	cython_lint-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lint Cython files
WWW=		https://github.com/MarcoGorelli/cython-lint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycodestyle>=0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenize-rt>=3.2.0:devel/py-tokenize-rt@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist cython_run noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
