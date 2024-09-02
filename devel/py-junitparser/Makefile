PORTNAME=	junitparser
DISTVERSION=	3.2.0
CATEGORIES=	devel net
#MASTER_SITES=	PYPI # some test files are missing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Manipulating JUnit/xUnit Result XML files
WWW=		https://junitparser.readthedocs.io/en/latest/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	weiwei

NO_ARCH=	yes

.include <bsd.port.mk>
