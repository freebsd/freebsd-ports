PORTNAME=	hatch-vcs
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hatch_vcs-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hatch plugin for versioning with your preferred VCS
WWW=		https://github.com/ofek/hatch-vcs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.1.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.1.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.4.0:devel/py-setuptools_scm@${PY_FLAVOR}
TEST_DEPENDS=	git:devel/git

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
