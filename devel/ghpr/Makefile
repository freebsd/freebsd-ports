PORTNAME=	ghpr
PORTVERSION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	GitHub Pull Request landing tool for FreeBSD
WWW=		https://github.com/bsdimp/ghpr

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	gh:devel/gh \
		git:devel/git
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp

NO_ARCH=	yes

.include <bsd.port.mk>
