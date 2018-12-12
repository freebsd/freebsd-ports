# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	bx-python
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}python-lzo>0:archivers/py-python-lzo@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		compiler python
USE_GITHUB=	yes
GH_ACCOUNT=	bxlab
USE_PYTHON=	autoplist cython distutils

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bx -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
