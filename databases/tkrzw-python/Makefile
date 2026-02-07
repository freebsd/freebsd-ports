PORTNAME=	tkrzw
DISTVERSION=	0.1.32
CATEGORIES=	databases python
MASTER_SITES=	https://dbmx.net/${PORTNAME}/pkg-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${DISTVERSION}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Python interface for Tkrzw, successor of Kyoto Cabinet
WWW=		https://dbmx.net/tkrzw/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtkrzw.so:databases/tkrzw

USES=		localbase python
USE_PYTHON=	autoplist distutils flavors

LDFLAGS+=	-Wl,--as-needed

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
