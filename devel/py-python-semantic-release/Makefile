PORTNAME=	python-semantic-release
PORTVERSION=	10.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-semantic-release/python-semantic-release/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_semantic_release-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatic Semantic Versioning for Python projects
WWW=		https://python-semantic-release.readthedocs.io/en/latest/ \
		https://github.com/python-semantic-release/python-semantic-release

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.42<1:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.0<8.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-option-group>=0.5<1:devel/py-click-option-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>=1.2<2:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dotty-dict>=1.3<2:devel/py-dotty-dict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.0<4:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=6.0<7:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gitlab>=4.0.0<7.0.0:devel/py-python-gitlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=14.0<15:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.5<2:devel/py-shellingham@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11<1:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
