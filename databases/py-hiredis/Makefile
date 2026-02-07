PORTNAME=	hiredis
PORTVERSION=	3.2.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Python extension that wraps hiredis
WWW=		https://github.com/pietern/hiredis-py

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhiredis.so:databases/hiredis

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
