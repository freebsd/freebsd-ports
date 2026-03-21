PORTNAME=	cyclopts
DISTVERSION=	4.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intuitive, easy CLIs based on type hints
WWW=		https://github.com/BrianPugh/cyclopts

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=23.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.15:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.4:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-rst>=1.3.1:textproc/py-rich-rst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.6.0:textproc/py-rich@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.10.0:net/py-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.8.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
