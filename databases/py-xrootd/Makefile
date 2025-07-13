PORTNAME=	xrootd
PORTVERSION=	5.8.4
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for XRootD (eXtended ROOT Daemon)
WWW=		https://xrootd.slac.stanford.edu/ \
		https://github.com/xrootd/xrootd/tree/master/bindings/python \
		https://github.com/xrootd/xrootd

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/../../COPYING.LGPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libXrdCl.so:databases/xrootd

USES=		cmake:indirect python
USE_PYTHON=	autoplist concurrent pep517

WRKSRC_SUBDIR=	bindings/python

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
