# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	orafce
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oracle's compatibility functions and packages for PostgreSQL

LICENSE=	PostgreSQL

USES=		gmake bison pgsql:9.2+
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_TAGNAME=	ffea9cc

WANT_PGSQL=	server

PLIST_FILES=	lib/postgresql/orafce.so \
		share/postgresql/extension/orafce--3.2--3.3.sql \
		share/postgresql/extension/orafce--3.3--3.4.sql \
		share/postgresql/extension/orafce--3.4.sql \
		share/postgresql/extension/orafce.control

PORTDOCS=	README.asciidoc

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/DOCS = README/#&/' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/orafce.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
