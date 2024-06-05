PORTNAME=	prefix
PORTVERSION=	1.2.10
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Prefix Range module for PostgreSQL
WWW=		https://github.com/dimitri/prefix

LICENSE=	PostgreSQL

USES=		gmake pgsql:11+
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	dimitri

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/prefix.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} ;	${INSTALL_DATA} README.md TESTS.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
