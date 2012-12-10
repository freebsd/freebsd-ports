# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.7.2
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

USE_GITHUB=		yes
GH_ACCOUNT=		andymccurdy
GH_PROJECT=		${PORTNAME}-py
GH_COMMIT=		c02231c
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=		HIREDIS
HIREDIS_DESC=		Add py-hiredis C extension support
# bypass infrastructure bug
OPTIONSFILE=		${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHIREDIS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}hiredis>0:${PORTSDIR}/databases/py-hiredis
.endif

.include <bsd.port.mk>
