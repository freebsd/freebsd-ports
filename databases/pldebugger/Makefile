PORTNAME=	pldebugger
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL pl/pgsql Debugger API

LICENSE=	ART20

USES=		gmake pgsql

LLD_UNSAFE=	yes
MAKE_ENV=	USE_PGXS=1
WANT_PGSQL=	server

DOCSDIR=	${PREFIX}/share/doc/postgresql/extension

USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

PORTSCOUT=	limit:^[0-9]

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plugin_debugger.so

.include <bsd.port.mk>
