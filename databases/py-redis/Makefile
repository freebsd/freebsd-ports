# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.8.0
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

USE_GITHUB=		yes
GH_ACCOUNT=		andymccurdy
GH_PROJECT=		${PORTNAME}-py
GH_COMMIT=		678f353

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=		HIREDIS
HIREDIS_DESC=		High performance response parser (via hiredis)
OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHIREDIS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}hiredis>0:${PORTSDIR}/databases/py-hiredis
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
