PORTNAME=	gitless
PORTVERSION=	0.8.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Version control system built on top of Git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git \
		${PYTHON_PKGNAMEPREFIX}clint>=0.3.6:devel/py-clint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.28.2:devel/py-pygit2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sh>=1.11:devel/py-sh@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v

.include <bsd.port.mk>
