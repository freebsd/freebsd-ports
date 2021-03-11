# $FreeBSD$

PORTNAME=	pg_hashids
PORTVERSION=	1.3
CATEGORIES=	databases

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	PostgreSQL extension for generates short, unique, non-sequential ids from numbers

LICENSE=	MIT

USES=		gmake pgsql:9.6+
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	iCyberon
GH_TAGNAME=	83398bcb

LLD_UNSAFE=	yes

PLIST_FILES=	lib/postgresql/${PORTNAME}.so \
		share/postgresql/extension/${PORTNAME}--${PORTVERSION}.sql \
		share/postgresql/extension/${PORTNAME}--1.0--1.1.sql \
		share/postgresql/extension/${PORTNAME}--1.1--1.2.sql \
		share/postgresql/extension/${PORTNAME}--1.2--${PORTVERSION}.sql \
		share/postgresql/extension/${PORTNAME}--1.2.1--${PORTVERSION}.sql \
		share/postgresql/extension/${PORTNAME}.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/${PORTNAME}.so

.include <bsd.port.mk>
