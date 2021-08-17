# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	bx-python
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.11-6
DISTVERSIONSUFFIX=	-gbd714e3 # 0.8.11 has a plist problem that bd714e3 doesn't have
CATEGORIES=	biology python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler python:3.6+
USE_PYTHON=	autoplist cython distutils

USE_GITHUB=	yes
GH_ACCOUNT=	bxlab

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bx -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
