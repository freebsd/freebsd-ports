PORTNAME=	meliae
PORTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	https://launchpadlibrarian.net/478629999/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python Memory Usage Analyzer

LICENSE=	GPLv3
#LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist cython
TEST_TARGET=	check  # test fails

.include <bsd.port.mk>
