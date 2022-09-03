PORTNAME=	llfuse
PORTVERSION=	1.3.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stdin@niklaas.eu
COMMENT=	Python bindings for low-level FUSE API

LICENSE=	LGPL20+

py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}contextlib2>0:devel/py-contextlib2@${PY_FLAVOR}

USES=		compiler:c++11-lang fuse pkgconfig python:-3.10 # 3.11 fails because llfuse.c includes longintrepr.h directly, see https://docs.python.org/3.11/whatsnew/3.11.html
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/llfuse*.so

.include <bsd.port.mk>
