PORTNAME=	jira
PORTVERSION=	3.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library to ease use of the JIRA 5 REST APIs
WWW=		https://github.com/pycontribs/jira

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>=1.1:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=1.1.0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>0:www/py-requests-toolbelt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

OPTIONS_DEFINE=		MAGIC SHELL
OPTIONS_DEFAULT=	MAGIC SHELL

MAGIC_DESC=	Enable Content-Type Auto-detection
PARALLEL_DESC=	Enable asyrequests
SHELL_DESC=	Enable interactive shell

MAGIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filemagic>=1.6:devel/py-filemagic@${PY_FLAVOR}
SHELL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=4.0.0:devel/ipython@${PY_FLAVOR}

.include <bsd.port.mk>
