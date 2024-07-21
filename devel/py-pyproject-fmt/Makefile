PORTNAME=	pyproject-fmt
PORTVERSION=	2.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyproject_fmt-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format your pyproject.toml file
WWW=		https://github.com/tox-dev/pyproject-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.4:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.25:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyproject-fmt-rust>=1.1.5<1.1.5_99:devel/py-pyproject-fmt-rust@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
