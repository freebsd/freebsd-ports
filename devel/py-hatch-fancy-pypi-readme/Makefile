PORTNAME=	hatch-fancy-pypi-readme
PORTVERSION=	24.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hatch_fancy_pypi_readme-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fancy PyPI READMEs with Hatch
WWW=		https://github.com/hynek/hatch-fancy-pypi-readme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
