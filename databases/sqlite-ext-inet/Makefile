# New ports collection makefile for:	sqlite-ext/inet
# Date created:		30 Jul 2009
# Whom:			Pavel Volkov <pol@iib.ru>
#
# $FreeBSD$
#

PORTNAME=	sqlite-ext-inet
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	http://mobigroup.ru/files/sqlite-ext/inet/
DISTFILES=	ipv4-ext.c ipv4-ext.sql

MAINTAINER=	pol@iib.ru
COMMENT=	Library will provide the ipv4 functions in SQL queries

USE_SQLITE=	yes

DIST_SUBDIR=	sqlite-ext
NO_WRKSUBDIR=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}/

PLIST_FILES=	libexec/${DIST_SUBDIR}/libsqliteipv4.so
PLIST_DIRS=	libexec/${DIST_SUBDIR}
.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DATADIR%%/ipv4-ext.sql %%DATADIR%%/README.txt
PLIST_DIRS+=	%%DATADIR%%
.endif

CFLAGS+=	-I${PREFIX}/include -fPIC -lm -shared

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} ipv4-ext.c -o libsqliteipv4.so

do-install:
	${MKDIR} ${PREFIX}/libexec/${DIST_SUBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libsqliteipv4.so ${PREFIX}/libexec/${DIST_SUBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ipv4-ext.sql ${DATADIR}
	${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ipv4-ext.c > ${WRKSRC}/README.txt
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DATADIR}
.endif

.include <bsd.port.mk>
