PORTNAME=	hiredis
PORTVERSION=	2.0.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Python extension that wraps hiredis
WWW=		https://github.com/pietern/hiredis-py

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhiredis.so:databases/hiredis

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
