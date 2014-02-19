# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	simplejson
PORTVERSION=	3.3.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simple, fast, extensible JSON encoder/decoder

LICENSE_COMB=	dual
LICENSE=	MIT PSFL

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

regression-test test: build
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
