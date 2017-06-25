# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pldebugger
PORTVERSION=	9.6.0
CATEGORIES=	databases
MASTER_SITES=	https://git.postgresql.org/gitweb/?p=pldebugger.git;a=snapshot;h=REL-${PORTVERSION:C/\./_/g};sf=tgz;dummy=/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	PostgreSQL pl/pgsql Debugger API

LICENSE=	ART20

USES=		gmake pgsql
WANT_PGSQL=	server

DOCSDIR=	${PREFIX}/share/doc/postgresql/extension

WRKSRC=		${WRKDIR}/${PORTNAME}-REL-${PORTVERSION:C/\./_/g}-d02e829

MAKE_ENV=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plugin_debugger.so

.include <bsd.port.mk>
