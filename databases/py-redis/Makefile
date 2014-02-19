# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.9.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

OPTIONS_DEFINE=	HIREDIS
HIREDIS_DESC=	High performance response parser (via hiredis)

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>0:${PORTSDIR}/databases/py-hiredis

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	andymccurdy
GH_PROJECT=	${PORTNAME}-py
GH_COMMIT=	91a0b8b

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
