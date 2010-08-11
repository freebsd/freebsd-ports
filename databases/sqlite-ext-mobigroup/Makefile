# New ports collection makefile for:	sqlite-ext-mobigroup
# Date created:		28 Jul 2010
# Whom:			Pavel Volkov <pavelivolkov@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	sqlite-ext-mobigroup
PORTVERSION=	4
DISTVERSIONPREFIX=	mobigroup.
CATEGORIES=	databases
MASTER_SITES=	http://mobigroup.ru/debian/pool-squeeze/main/s/sqlite3/ \
		LOCAL/glarkin
DISTNAME=	${SQLITE_NAME}_${SQLITE_VERSION}-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	A mobigroup functions library for SQLite

# Soon to be expired earlier version of the port
CONFLICTS=	sqlite-ext-inet-[0-9].*

USE_SQLITE=	yes

DIST_SUBDIR=	sqlite-ext
NO_WRKSUBDIR=	yes

SQLITE_NAME=	sqlite3
SQLITE_VERSION=	3.7.0

USE_LDCONFIG=	${PREFIX}/libexec/${DIST_SUBDIR}

OPTIONS=	INET "Provide the IPv4 functions in SQL queries" On \
		ENV "Provide getenv functions in SQL queries" Off \
		MD5 "Provide MD5 algorithm functions in SQL queries" Off

.include <bsd.port.pre.mk>

PLIST_DIRS=	libexec/${DIST_SUBDIR}
.ifndef NOPORTDOCS
PLIST_DIRS+=	%%DOCSDIR%%
.endif
.ifndef NOPORTEXAMPLES
PLIST_DIRS+=	%%EXAMPLESDIR%%
.endif

.ifdef WITH_INET
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqliteipv4.so
.ifndef NOPORTDOCS
PLIST_FILES+=	%%DOCSDIR%%/README-ipv4.txt
.endif
.ifndef NOPORTEXAMPLES
PLIST_FILES+=	%%EXAMPLESDIR%%/ipv4-ext.sql
.endif
.endif

.ifdef WITH_ENV
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqliteenv.so
.ifndef NOPORTDOCS
PLIST_FILES+=	%%DOCSDIR%%/README-env.txt
.endif
.endif

.ifdef WITH_MD5
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqlitemd5.so
.ifndef NOPORTDOCS
PLIST_FILES+=	%%DOCSDIR%%/README-md5.txt
.endif
.ifndef NOPORTEXAMPLES
PLIST_FILES+=	%%EXAMPLESDIR%%/md5.sql
.endif
.endif

.if !defined(WITH_INET) && !defined(WITH_ENV) && !defined(WITH_MD5)
IGNORE=		requires at least one selected module to build
.endif

CFLAGS+=	-I${PREFIX}/include -fPIC -lm -shared

do-build:
.ifdef WITH_INET
	@cd ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/inet && \
		${CC} ${CFLAGS} ipv4-ext.c -o libsqliteipv4.so
.endif
.ifdef WITH_ENV
	@cd ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/env && \
		${CC} ${CFLAGS} env.c -o libsqliteenv.so
.endif
.ifdef WITH_MD5
	@cd ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/md5 && \
		${CC} ${CFLAGS} md5.c -o libsqlitemd5.so
.endif

do-install:
.ifdef WITH_INET
	@${MKDIR} ${PREFIX}/libexec/${DIST_SUBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/inet/libsqliteipv4.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${MKDIR} ${DOCSDIR}
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/inet/ipv4-ext.c > ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/inet/README-ipv4.txt
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/inet/README-ipv4.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${MKDIR} ${EXAMPLESDIR}
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/inet/ipv4-ext.sql ${EXAMPLESDIR}
.	endif
.endif
.ifdef WITH_ENV
	@${MKDIR} ${PREFIX}/libexec/${DIST_SUBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/env/libsqliteenv.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${MKDIR} ${DOCSDIR}
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/env/env.c > ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/env/README-env.txt
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/env/README-env.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${MKDIR} ${EXAMPLESDIR}
.	endif
.endif
.ifdef WITH_MD5
	@${MKDIR} ${PREFIX}/libexec/${DIST_SUBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/md5/libsqlitemd5.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${MKDIR} ${DOCSDIR}
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/md5/md5.c > ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/md5/README-md5.txt
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/md5/README-md5.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${MKDIR} ${EXAMPLESDIR}
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}-${SQLITE_VERSION}/ext/md5/md5.sql ${EXAMPLESDIR}
.	endif
.endif

.include <bsd.port.post.mk>
