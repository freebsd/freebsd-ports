# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.7.6
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

USE_GITHUB=		yes
GH_ACCOUNT=		andymccurdy
GH_PROJECT=		${PORTNAME}-py
GH_COMMIT=		a6302d9

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=		HIREDIS
HIREDIS_DESC=		Add py-hiredis C extension support
OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHIREDIS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}hiredis>0:${PORTSDIR}/databases/py-hiredis
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
