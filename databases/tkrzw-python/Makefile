PORTNAME=	tkrzw
DISTVERSION=	0.1.32
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	https://dbmx.net/${PORTNAME}/pkg-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${DISTVERSION}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Python interface for Tkrzw, successor of Kyoto Cabinet
WWW=		https://dbmx.net/tkrzw/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libtkrzw.so:databases/tkrzw

USES=		localbase python
USE_PYTHON=	autoplist flavors pep517

LDFLAGS+=	-Wl,--as-needed

post-patch:
	@${REINPLACE_CMD} -e 's|0.1.30|${DISTVERSION}|' ${WRKSRC}/setup.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
