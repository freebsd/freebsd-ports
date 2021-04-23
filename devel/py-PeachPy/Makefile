PORTNAME=	PeachPy
DISTVERSION=	0.0.1
PORTEPOCH=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable efficient assembly codegen in higher-level Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opcodes>=0.3.13:devel/py-opcodes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	Maratyszcza # the latest version is here, not on PyPI
GH_TAGNAME=	01d1515
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
