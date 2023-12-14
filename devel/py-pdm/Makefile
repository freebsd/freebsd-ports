PORTNAME=	pdm
PORTVERSION=	2.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Master
WWW=		https://pdm-project.org/ \
		https://github.com/pdm-project/pdm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.13.0:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}findpython>=0.4.0<1.0.0:devel/py-findpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0.7<0.8:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject_hooks>=0:devel/py-pyproject_hooks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.15:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resolvelib1>=1.0.1:devel/py-resolvelib1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.3.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.3.2:devel/py-shellingham@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.1<1:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unearth>=0.12.1:devel/py-unearth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	COOKIECUTTER COPIER KEYRING
OPTIONS_DEFAULT=KEYRING
COOKIECUTTER_DESC=	Use cookiecutter to generate project
COPIER_DESC=		Use copier to generate project
KEYRING_DESC=		Use keyring to save credentials

COOKIECUTTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cookiecutter>=0:devel/py-cookiecutter@${PY_FLAVOR} \
COPIER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}copier>=8.0.0:devel/py-copier@${PY_FLAVOR} \
KEYRING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>=0,1:security/py-keyring@${PY_FLAVOR} \

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=5:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}truststore>=0:security/py-truststore@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
