PORTNAME=	pymeeus
PORTVERSION=	0.3.6
CATEGORIES=	astro science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyMeeus-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python implementation of Jean Meeus astronomical routines

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
