PORTNAME=	postgresql
DISTVERSION=	18_00_0006
DISTVERSIONPREFIX=REL-
CATEGORIES=	databases
PKGNAMESUFFIX=	-odbc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL ODBC driver
WWW=		https://github.com/postgresql-interfaces/psqlodbc/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		autoreconf compiler:c11 libtool pgsql
USE_CSTD=	gnu11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	postgresql-interfaces
GH_PROJECT=	psqlodbc

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
