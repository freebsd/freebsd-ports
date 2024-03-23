PORTNAME=	poetry
PORTVERSION=	1.8.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-poetry/poetry/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python dependency management and packaging made easy
WWW=		https://python-poetry.org/ \
		https://github.com/python-poetry/poetry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.5.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=1.0.3<2:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cleo>=2.1.0<3:devel/py-cleo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crashtest>=0.4.1<0.5:devel/py-crashtest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.21.2<0.22:devel/py-dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastjsonschema>=2.18.0<3:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0.7.0<0.8:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=23.9.0,1<25,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.7.0<5:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.9.4<2:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3.0.0<5:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=1.9.0<1.9.0_99:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-plugin-export>=1.6.0<2:devel/py-poetry-plugin-export@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject_hooks>=1.0.0<2:devel/py-pyproject_hooks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=1.0.0<2:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.5<2:devel/py-shellingham@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.4<1.0.0:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2022.5.19:devel/py-trove-classifiers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.23.0<21:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

BINARY_ALIAS=	git=false
NO_ARCH=	yes

OPTIONS_DEFINE=	FILECACHE
OPTIONS_DEFAULT=FILECACHE
FILECACHE_DESC=	File cache support

FILECACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.14.0<0.15:www/py-cachecontrol@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.4:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=2.0.1<3:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
