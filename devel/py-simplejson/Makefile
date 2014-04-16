# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	simplejson
PORTVERSION=	3.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simple, fast, extensible JSON encoder/decoder

# dual-licensed under MIT and Academic Free License version 2.1
LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

regression-test test: build
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
