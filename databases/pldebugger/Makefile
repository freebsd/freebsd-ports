PORTNAME=	pldebugger
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL pl/pgsql Debugger API

LICENSE=	ART20

USES=		gmake pgsql
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB
LLD_UNSAFE=	yes
MAKE_ENV=	USE_PGXS=1

DOCSDIR=	${PREFIX}/share/doc/postgresql/extension

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plugin_debugger.so

.include <bsd.port.mk>
