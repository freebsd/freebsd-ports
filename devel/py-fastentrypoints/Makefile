PORTNAME=	fastentrypoints
PORTVERSION=	0.12
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Makes entry_points specified in setup.py load more quickly

LICENSE=	BSD2CLAUSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/test && ${PYTHON_CMD} runtest.py

.include <bsd.port.mk>
