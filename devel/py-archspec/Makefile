PORTNAME=	archspec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to query system architecture
WWW=		https://github.com/archspec/archspec

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_TUPLE=	archspec:archspec-json:d844bb3:json/archspec/json

NO_ARCH=	yes

MAKE_ENV=	GIT_DIR=${WRKDIR} # workaround for https://github.com/python-poetry/poetry/issues/5547

.include <bsd.port.mk>
