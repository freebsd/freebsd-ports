PORTNAME=	archspec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to query system architecture
WWW=		https://archspec.readthedocs.io/en/latest/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 test fails, see https://github.com/archspec/archspec-json/issues/98

USE_GITHUB=	yes
GH_TUPLE=	archspec:archspec-json:edd3de7:json/archspec/json \
		archspec:cpuid:5b381ed:cpuid/archspec/vendor/cpuid

NO_ARCH=	yes

MAKE_ENV=	GIT_DIR=${WRKDIR} # workaround for https://github.com/python-poetry/poetry/issues/5547

.include <bsd.port.mk>
