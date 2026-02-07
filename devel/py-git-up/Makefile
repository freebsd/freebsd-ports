PORTNAME=	git-up
PORTVERSION=	2.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	git_up-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of 'git up'
WWW=		https://github.com/msiemens/PyGitUp

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.0<0.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1<4:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0<26:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=3.2<4:devel/py-termcolor@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

DOS2UNIX_GLOB=	*.py

.include <bsd.port.mk>
