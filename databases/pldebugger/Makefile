PORTNAME=	pldebugger
PORTVERSION=	1.0.20181016
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://git.postgresql.org/gitweb/?p=pldebugger.git;a=snapshot;h=c3ac72942c6ba2e3b701a5291b1f6cf8f596b57c;sf=tgz;dummy=/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	PostgreSQL pl/pgsql Debugger API

LICENSE=	ART20

USES=		gmake pgsql
LLD_UNSAFE=	yes
WANT_PGSQL=	server

DOCSDIR=	${PREFIX}/share/doc/postgresql/extension

WRKSRC=		${WRKDIR}/${PORTNAME}-c3ac729

MAKE_ENV=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plugin_debugger.so

.include <bsd.port.mk>
