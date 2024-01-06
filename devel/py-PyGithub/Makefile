PORTNAME=	PyGithub
DISTVERSION=	2.1.1
CATEGORIES=	devel www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGithub-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python library implementing the full GitHub API v3
WWW=		https://github.com/jacquev6/PyGithub

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.4.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.4.0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
