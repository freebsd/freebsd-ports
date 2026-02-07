PORTNAME=	bashlex
DISTVERSION=	0.18
CATEGORIES=	devel science
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python parser for bash
WWW=		https://github.com/idank/bashlex

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	idank

NO_ARCH=	yes

# tests as of 0.18: 60 passed, 5 warnings in 25.54s

.include <bsd.port.mk>
