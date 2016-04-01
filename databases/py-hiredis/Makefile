# Created by: Denis Generalov <gd@rambler-co.ru>
# $FreeBSD$

PORTNAME=	hiredis
PORTVERSION=	0.2.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Python extension that wraps hiredis

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhiredis.so:databases/hiredis

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
