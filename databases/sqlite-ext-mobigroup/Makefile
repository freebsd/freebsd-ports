# New ports collection makefile for:	sqlite-ext-mobigroup
# Date created:		28 Jul 2010
# Whom:			Pavel Volkov <pavelivolkov@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	sqlite-ext-mobigroup
PORTVERSION=	3.7.5.1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://mobigroup.ru/debian/pool-squeeze/main/s/sqlite3/
DISTNAME=	sqlite3_${PORTVERSION:R}-mobigroup.${PORTVERSION:E}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	A mobigroup functions library for SQLite

USE_SQLITE=	yes

DIST_SUBDIR=	sqlite-ext
WRKSRC=		${WRKDIR}/sqlite3-${PORTVERSION:R}

USE_LDCONFIG=	${PREFIX}/libexec/${DIST_SUBDIR}

OPTIONS=	COMPRESS "compress content into a blob using libz" off \
		ENV "implements the getenv" off \
		INET "provide the ipv4 functions in SQL queries" on \
		MD5 "implements the MD5 message-digest algorithm" off

PLIST_DIRS=	libexec/${DIST_SUBDIR}
PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

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
	@cd ${WRKSRC}/ext/_compress && \
		${CC} -lz ${CFLAGS} compress.c -o libsqlitecompress.so
.endif
.ifdef WITH_INET
	@cd ${WRKSRC}/ext/inet && \
		${CC} ${CFLAGS} ipv4-ext.c -o libsqliteipv4.so
.endif
.ifdef WITH_ENV
	@cd ${WRKSRC}/ext/env && \
		${CC} ${CFLAGS} env.c -o libsqliteenv.so
.endif
.ifdef WITH_MD5
	@cd ${WRKSRC}/ext/md5 && \
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
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/_compress/libsqlitecompress.so ${PREFIX}/libexec/${DIST_SUBDIR}
.endif
.ifdef WITH_INET
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/inet/libsqliteipv4.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ext/inet/ipv4-ext.c > ${WRKSRC}/ext/inet/README-ipv4.txt
		@${INSTALL_DATA} ${WRKSRC}/ext/inet/README-ipv4.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${INSTALL_DATA} ${WRKSRC}/ext/inet/ipv4-ext.sql ${EXAMPLESDIR}
.	endif
.endif
.ifdef WITH_ENV
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/env/libsqliteenv.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ext/env/env.c > ${WRKSRC}/ext/env/README-env.txt
		@${INSTALL_DATA} ${WRKSRC}/ext/env/README-env.txt ${DOCSDIR}
.	endif
.endif
.ifdef WITH_MD5
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/md5/libsqlitemd5.so ${PREFIX}/libexec/${DIST_SUBDIR}
.	ifndef NOPORTDOCS
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ext/md5/md5.c > ${WRKSRC}/ext/md5/README-md5.txt
		@${INSTALL_DATA} ${WRKSRC}/ext/md5/README-md5.txt ${DOCSDIR}
.	endif
.	ifndef NOPORTEXAMPLES
		@${INSTALL_DATA} ${WRKSRC}/ext/md5/md5.sql ${EXAMPLESDIR}
.	endif
.endif

.include <bsd.port.mk>
