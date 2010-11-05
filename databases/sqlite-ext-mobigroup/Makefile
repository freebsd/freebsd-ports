# New ports collection makefile for:	sqlite-ext-mobigroup
# Date created:		28 Jul 2010
# Whom:			Pavel Volkov <pavelivolkov@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	sqlite-ext-mobigroup
PORTVERSION=	1
DISTVERSIONPREFIX=	mobigroup.
CATEGORIES=	databases
MASTER_SITES=	http://mobigroup.ru/debian/pool-squeeze/main/s/sqlite3/ \
		LOCAL/glarkin
PKGNAMESUFFIX=	-${SQLITE_VERSION}
DISTNAME=	${SQLITE_NAME}_${SQLITE_VERSION}-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	A mobigroup functions library for SQLite

# Soon to be expired earlier version of the port
CONFLICTS=	sqlite-ext-inet-[0-9].*

USE_SQLITE=	yes

DIST_SUBDIR=	sqlite-ext
NO_WRKSUBDIR=	yes

SQLITE_NAME=	sqlite3
SQLITE_VERSION=	3.7.2

USE_LDCONFIG=	${PREFIX}/libexec/${DIST_SUBDIR}

OPTIONS=	\
		COMPRESS "compress content into a blob using libz" off \
		INET "provide the ipv4 functions in SQL queries" on \
		MD5 "implements the MD5 message-digest algorithm" off \
		ENV "implements the getenv" off \

.include <bsd.port.pre.mk>

PLIST_DIRS=	libexec/${DIST_SUBDIR}
PORTDOCS=	*
PORTEXAMPLES=	*

.ifdef WITH_COMPRESS
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqlitecompress.so
.endif
.ifdef WITH_INET
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqliteipv4.so
.endif
.ifdef WITH_ENV
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqliteenv.so
.endif
.ifdef WITH_MD5
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqlitemd5.so
.endif

CFLAGS+=	-I${PREFIX}/include -fPIC -lm -shared

do-build:
.ifdef WITH_COMPRESS
	@cd ${WRKSRC}/${SQLITE_NAME}/ext/_compress && \
		${CC} -lz ${CFLAGS} compress.c -o libsqlitecompress.so
.endif
.ifdef WITH_INET
	@cd ${WRKSRC}/${SQLITE_NAME}/ext/inet && \
		${CC} ${CFLAGS} ipv4-ext.c -o libsqliteipv4.so
.endif
.ifdef WITH_ENV
	@cd ${WRKSRC}/${SQLITE_NAME}/ext/env && \
		${CC} ${CFLAGS} env.c -o libsqliteenv.so
.endif
.ifdef WITH_MD5
	@cd ${WRKSRC}/${SQLITE_NAME}/ext/md5 && \
		${CC} ${CFLAGS} md5.c -o libsqlitemd5.so
.endif

do-install:
	@${MKDIR} ${PREFIX}/libexec/${DIST_SUBDIR}
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.endif
.ifndef NOPORTEXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
.endif
.ifdef WITH_COMPRESS
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}/ext/_compress/libsqlitecompress.so ${PREFIX}/libexec/${DIST_SUBDIR}
.endif
.ifdef WITH_INET
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}/ext/inet/libsqliteipv4.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/${SQLITE_NAME}/ext/inet/ipv4-ext.c > ${WRKSRC}/${SQLITE_NAME}/ext/inet/README-ipv4.txt
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}/ext/inet/README-ipv4.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}/ext/inet/ipv4-ext.sql ${EXAMPLESDIR}
.	endif
.endif
.ifdef WITH_ENV
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}/ext/env/libsqliteenv.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/${SQLITE_NAME}/ext/env/env.c > ${WRKSRC}/${SQLITE_NAME}/ext/env/README-env.txt
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}/ext/env/README-env.txt ${DOCSDIR}
.	endif
.endif
.ifdef WITH_MD5
	@${INSTALL_PROGRAM} ${WRKSRC}/${SQLITE_NAME}/ext/md5/libsqlitemd5.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/${SQLITE_NAME}/ext/md5/md5.c > ${WRKSRC}/${SQLITE_NAME}/ext/md5/README-md5.txt
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}/ext/md5/README-md5.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${INSTALL_DATA} ${WRKSRC}/${SQLITE_NAME}/ext/md5/md5.sql ${EXAMPLESDIR}
.	endif
.endif

.include <bsd.port.post.mk>
