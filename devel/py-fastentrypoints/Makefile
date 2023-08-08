PORTNAME=	fastentrypoints
PORTVERSION=	0.12
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Makes entry_points specified in setup.py load more quickly
WWW=		https://github.com/ninjaaron/fast-entry_points

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/test && ${PYTHON_CMD} runtest.py

.include <bsd.port.mk>
