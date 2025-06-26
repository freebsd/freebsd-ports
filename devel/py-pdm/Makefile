PORTNAME=	pdm
PORTVERSION=	2.25.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Master
WWW=		https://pdm-project.org/ \
		https://github.com/pdm-project/pdm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-build-locked>=0:devel/py-pdm-build-locked@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.8.30:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dep-logic>=0.5:devel/py-dep-logic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.13:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}findpython>=0.6.0<1.0.0:devel/py-findpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hishel>=0.0.32:devel/py-hishel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=1.0.6:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.20<1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}id>=1.5.0:devel/py-id@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0.7<0.8:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbs-installer>=2025.6.6:devel/py-pbs-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-hooks>=0:devel/py-pyproject-hooks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.15:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resolvelib1>=1.1:devel/py-resolvelib1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.3.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.3.2:devel/py-shellingham@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.1<1:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unearth>=0.17.5:devel/py-unearth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	COOKIECUTTER COPIER KEYRING MSGPACK
OPTIONS_DEFAULT=KEYRING MSGPACK
COOKIECUTTER_DESC=	Use cookiecutter to generate project
COPIER_DESC=		Use copier to generate project
KEYRING_DESC=		Use keyring to save credentials
MSGPACK_DESC=		Use msgpack to process serializer

COOKIECUTTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cookiecutter>=0:devel/py-cookiecutter@${PY_FLAVOR} \
COPIER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}copier>=8.0.0:devel/py-copier@${PY_FLAVOR} \
KEYRING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>=0,1:security/py-keyring@${PY_FLAVOR} \
MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0:devel/py-msgpack@${PY_FLAVOR} \

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}truststore>=0.9:security/py-truststore@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
