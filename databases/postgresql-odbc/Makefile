# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	12.02.0000
CATEGORIES=	databases
MASTER_SITES=	PGSQL/odbc/versions/src
PKGNAMESUFFIX=	-odbc
DISTNAME=	psqlodbc-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL ODBC driver

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		compiler:c11 libtool pgsql
USE_CSTD=	gnu11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unixodbc=${LOCALBASE}
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/postgresql/odbc
EXAMPLESDIR=	${PREFIX}/share/examples/postgresql/odbc

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	lib/psqlodbcw.so lib/psqlodbca.so

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.sql ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
