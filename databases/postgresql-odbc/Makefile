# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	09.05.0200
CATEGORIES=	databases
MASTER_SITES=	PGSQL/odbc/versions/src
PKGNAMESUFFIX=	-odbc
DISTNAME=	psqlodbc-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL ODBC driver

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		libtool pgsql
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unixodbc=${LOCALBASE}
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/postgresql/odbc
EXAMPLESDIR=	${PREFIX}/share/examples/postgresql/odbc

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	lib/psqlodbcw.so

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.sql ${STAGEDIR}${EXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
