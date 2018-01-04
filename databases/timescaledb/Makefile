# Created by: Kevin Bowling <kbowling@freebsd.org>
# $FreeBSD$

PORTNAME=	timescaledb
PORTVERSION=	0.8.0
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Time-series database built on PostgreSQL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cmake:outsource pgsql:9.6,10
USE_LDCONFIG=	yes

USE_GITHUB=	YES
GH_ACCOUNT=	timescale

WANT_PGSQL=	server

SUB_LIST+=	PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message

PLIST_FILES=	lib/postgresql/timescaledb.so \
		share/postgresql/extension/timescaledb--0.1.0--0.2.0.sql \
		share/postgresql/extension/timescaledb--0.2.0--0.3.0.sql \
		share/postgresql/extension/timescaledb--0.3.0--0.4.0.sql \
		share/postgresql/extension/timescaledb--0.4.0--0.4.1.sql \
		share/postgresql/extension/timescaledb--0.4.1--0.4.2.sql \
		share/postgresql/extension/timescaledb--0.4.2--0.5.0.sql \
		share/postgresql/extension/timescaledb--0.5.0--0.6.0.sql \
		share/postgresql/extension/timescaledb--0.6.0--0.6.1.sql \
		share/postgresql/extension/timescaledb--0.6.1--0.7.0.sql \
		share/postgresql/extension/timescaledb--0.6.1--0.7.1.sql \
		share/postgresql/extension/timescaledb--0.7.0--0.7.1.sql \
		share/postgresql/extension/timescaledb--0.7.1--0.8.0.sql \
		share/postgresql/extension/timescaledb--0.8.0.sql \
		share/postgresql/extension/timescaledb.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/timescaledb.so

.include <bsd.port.mk>
