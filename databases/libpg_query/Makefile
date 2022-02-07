# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	libpg_query
DISTVERSION=	13-2.1.0
CATEGORIES=	databases devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	C library for accessing the PostgreSQL parser outside of the server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe gmake pgsql
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lfittl

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpg_query.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pg_query.h ${STAGEDIR}${PREFIX}/include/

PLIST_FILES=	include/pg_query.h \
		lib/libpg_query.a

.include <bsd.port.mk>
