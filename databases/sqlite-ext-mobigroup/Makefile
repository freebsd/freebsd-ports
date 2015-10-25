# Created by: Pavel Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	sqlite-ext-mobigroup
PORTVERSION=	3.7.5.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://mobigroup.ru/debian/pool-squeeze/main/s/sqlite3/
DISTNAME=	sqlite3_${PORTVERSION:R}-mobigroup.${PORTVERSION:E}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	Mobigroup functions library for SQLite

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USE_SQLITE=	yes

DIST_SUBDIR=	sqlite-ext
WRKSRC=		${WRKDIR}/sqlite3-${PORTVERSION:R}

USE_LDCONFIG=	${PREFIX}/libexec/${DIST_SUBDIR}

OPTIONS_DEFINE=	COMPRESS ENV INET MD5 EXAMPLES DOCS
COMPRESS_DESC=	compress content into a blob using libz
ENV_DESC=	implements the getenv
INET_DESC=	provide the ipv4 functions in SQL queries
MD5_DESC=	implements the MD5 message-digest algorithm

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPRESS}
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqlitecompress.so
.endif
.if ${PORT_OPTIONS:MINET}
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqliteipv4.so
.endif
.if ${PORT_OPTIONS:MENV}
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqliteenv.so
.endif
.if ${PORT_OPTIONS:MMD5}
PLIST_FILES+=	libexec/${DIST_SUBDIR}/libsqlitemd5.so
.endif

CFLAGS+=	-I${PREFIX}/include -fPIC -lm -shared

do-build:
.if ${PORT_OPTIONS:MCOMPRESS}
	@cd ${WRKSRC}/ext/_compress && \
		${CC} -lz ${CFLAGS} compress.c -o libsqlitecompress.so
.endif
.if ${PORT_OPTIONS:MINET}
	@cd ${WRKSRC}/ext/inet && \
		${CC} ${CFLAGS} ipv4-ext.c -o libsqliteipv4.so
.endif
.if ${PORT_OPTIONS:MENV}
	@cd ${WRKSRC}/ext/env && \
		${CC} ${CFLAGS} env.c -o libsqliteenv.so
.endif
.if ${PORT_OPTIONS:MMD5}
	@cd ${WRKSRC}/ext/md5 && \
		${CC} ${CFLAGS} md5.c -o libsqlitemd5.so
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MCOMPRESS}
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/_compress/libsqlitecompress.so ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
.endif
.if ${PORT_OPTIONS:MINET}
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/inet/libsqliteipv4.so ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
.	if ${PORT_OPTIONS:MDOCS}
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ext/inet/ipv4-ext.c > ${WRKSRC}/ext/inet/README-ipv4.txt
		@${INSTALL_DATA} ${WRKSRC}/ext/inet/README-ipv4.txt ${STAGEDIR}${DOCSDIR}
.	endif
.	if ${PORT_OPTIONS:MEXAMPLES}
		@${INSTALL_DATA} ${WRKSRC}/ext/inet/ipv4-ext.sql ${STAGEDIR}${EXAMPLESDIR}
.	endif
.endif
.if ${PORT_OPTIONS:MENV}
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/env/libsqliteenv.so ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
.	if ${PORT_OPTIONS:MDOCS}
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ext/env/env.c > ${WRKSRC}/ext/env/README-env.txt
		@${INSTALL_DATA} ${WRKSRC}/ext/env/README-env.txt ${STAGEDIR}${DOCSDIR}
.	endif
.endif
.if ${PORT_OPTIONS:MMD5}
	@${INSTALL_PROGRAM} ${WRKSRC}/ext/md5/libsqlitemd5.so ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
.	if ${PORT_OPTIONS:MDOCS}
		@${SED} '/\/\*/d;/\*\//,$$d' ${WRKSRC}/ext/md5/md5.c > ${WRKSRC}/ext/md5/README-md5.txt
		@${INSTALL_DATA} ${WRKSRC}/ext/md5/README-md5.txt ${STAGEDIR}${DOCSDIR}
.	endif
.	if ${PORT_OPTIONS:MEXAMPLES}
		@${INSTALL_DATA} ${WRKSRC}/ext/md5/md5.sql ${STAGEDIR}${EXAMPLESDIR}
.	endif
.endif

.include <bsd.port.mk>
