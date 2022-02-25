PORTNAME=	meliae
PORTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	https://launchpadlibrarian.net/478629999/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python Memory Usage Analyzer

LICENSE=	GPLv3
#LICENSE_FILE=	${WRKSRC}/COPYING.txt

DEPRECATED=	does not build against Python-3.9
# See https://bugs.launchpad.net/meliae/+bug/1899379

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6-3.8
USE_PYTHON=	distutils autoplist cython
TEST_TARGET=	check  # test fails

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == 3.9
BROKEN=	build error: PyGC_HEAD is private in Python 3.9
.endif

.include <bsd.port.post.mk>
