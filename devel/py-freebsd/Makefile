# Created by: Hye-Shik Chang

PORTNAME=	freebsd
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python:3.6+
USE_PYTHON=	autoplist distutils unittest

USE_GITHUB=	yes
GH_ACCOUNT=	sobomax
GH_PROJECT=	py-freebsd

PYDISTUTILS_BUILD_TARGET=build_ext -i
TEST_ARGS=	discover -s tests

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/freebsd*.so

.include <bsd.port.mk>
