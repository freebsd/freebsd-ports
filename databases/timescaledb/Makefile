# Created by: Kevin Bowling <kbowling@freebsd.org>
# $FreeBSD$

PORTNAME=	timescaledb
PORTVERSION=	0.5.0
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Time-series database built on PostgreSQL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake pgsql:9.6
USE_LDCONFIG=	yes

USE_GITHUB=	YES
GH_ACCOUNT=	timescale

MAKE_ARGS=	PG_CONFIG=${LOCALBASE}/bin/pg_config USE_PGXS=1 \
		install_bin=/usr/bin/install

WANT_PGSQL=	server

PLIST_FILES=	lib/postgresql/timescaledb.so \
		share/postgresql/extension/timescaledb--0.1.0--0.2.0.sql \
		share/postgresql/extension/timescaledb--0.2.0--0.3.0.sql \
		share/postgresql/extension/timescaledb--0.3.0--0.4.0.sql \
		share/postgresql/extension/timescaledb--0.4.0--0.4.1.sql \
		share/postgresql/extension/timescaledb--0.4.1--0.4.2.sql \
		share/postgresql/extension/timescaledb--0.4.2--0.5.0.sql \
		share/postgresql/extension/timescaledb--0.5.0.sql \
		share/postgresql/extension/timescaledb.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/timescaledb.so

.include <bsd.port.mk>
