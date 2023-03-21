PORTNAME=	pdm
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Master
WWW=		https://github.com/pdm-project/pdm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-pep517>=1.0:devel/py-pdm-pep517@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}CacheControl>=0.12.11:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2022.6.15:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}findpython>=0.2.0:devel/py-findpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0.6<0.7:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-pep517>=1.0.0<2.0.0:devel/py-pdm-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep517>=0.11.0:devel/py-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.15:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resolvelib>=0.8<0.9:devel/py-resolvelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.3.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.3.2:devel/py-shellingham@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.8.0<1:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unearth>=0.6.0:devel/py-unearth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20:devel/py-virtualenv@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
