PORTNAME=	nose3
PORTVERSION=	1.3.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	nose extends unittest to make testing easier
WWW=		https://github.com/jayvdb/nose3

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}-nose

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m nose -v

.include <bsd.port.mk>
