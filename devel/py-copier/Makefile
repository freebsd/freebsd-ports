PORTNAME=	copier
PORTVERSION=	9.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering project templates
WWW=		https://copier.readthedocs.io/en/latest/ \
		https://github.com/copier-org/copier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.7.0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-dynamic-versioning>=1.1.0:devel/py-poetry-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dunamai>=1.7.0:devel/py-dunamai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcy>=1.17:devel/py-funcy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jinja2-ansible-filters>=1.3.1:devel/py-jinja2-ansible-filters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plumbum>=1.6.9:sysutils/py-plumbum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.4.2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7.1:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>=1.8.1:devel/py-questionary@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
