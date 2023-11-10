PORTNAME=	prospector
PORTVERSION=	1.10.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyse Python code by aggregating the result of other tools
WWW=		https://github.com/landscapeio/prospector

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dodgy>=0.2.1<0.3.0:devel/py-dodgy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.27<4.0.0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0.7.0<0.8:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8-naming>=0.3.3:devel/py-pep8-naming@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.9.0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>=2.0.0:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=2.2.0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylint-django>=2.5<2.6:devel/py-pylint-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylint-flask>=0.6<0.6_99:devel/py-pylint-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylint-plugin-utils>=0.7<0.8:devel/py-pylint-plugin-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requirements-detector>=1.2.0:devel/py-requirements-detector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setoptconf>=0.3.0<0.4:devel/py-setoptconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2<0.11.0:textproc/py-toml@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=2.8.3:devel/pylint

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
