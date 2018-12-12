# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	10.03.0000
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	PGSQL/odbc/versions/src
PKGNAMESUFFIX=	-odbc
DISTNAME=	psqlodbc-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL ODBC driver

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_powerpc64=	fails to compile: misc.h:58:21: expected ';' before 'dummy_for_check'

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		compiler:c11 libtool pgsql
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unixodbc=${LOCALBASE}
INSTALL_TARGET=	install-strip
CFLAGS+=	-std=c11

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
