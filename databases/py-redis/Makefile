# Created by:	Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.7.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://cloud.github.com/downloads/andymccurdy/redis-py/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

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
