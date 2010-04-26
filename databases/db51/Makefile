# New ports collection makefile for:	db50
# Date created:		2010-04-06
# Whom:			Matthias Andree <mandree@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	db50
PORTVERSION=	5.0.21.0
CATEGORIES=	databases java
MASTER_SITES=	http://download-west.oracle.com/berkeley-db/ \
		http://download-east.oracle.com/berkeley-db/ \
		http://download-uk.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
DISTNAME=	db-${PORTVERSION:R}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Oracle Berkeley DB, revision 5.0

BDBVER=		${PORTVERSION:R:R}
CONFIGURE_ARGS=	--enable-cxx --enable-stl \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME}
CONFIGURE_SCRIPT=	../dist/configure
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	install_include install_lib install_utilities
LIBTOOLFILES=	${CONFIGURE_SCRIPT}
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_docs docdir=${DOCSDIR}
PORTDOCS=		*
.endif

OPTIONS=	SQL "SQL API (EXPERIMENTAL)" OFF \
		JAVA "JAVA API (EXPERIMENTAL)" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_SQL)
CONFIGURE_ARGS+=	--enable-sql_codegen --enable-sql
PLIST_SUB+=	SQL=""
libdb_sql=	libdb_sql
.else
PLIST_SUB+=	SQL="@comment "
libdb_sql=
.endif

.if defined(WITH_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.5+
CONFIGURE_ARGS+=	--enable-java
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include" JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}"
PLIST_SUB+=	JAVA=""
libdb_java=	libdb_java
.else
PLIST_SUB+=	JAVA="@comment "
libdb_java=
.endif

post-patch:
	${REINPLACE_CMD} -e '/^DOCLIST/{s/csharp//;}' ${WRKSRC}/../dist/Makefile.in

post-install:
.for i in libdb libdb_cxx libdb_stl ${libdb_sql} ${libdb_java}
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${PREFIX}/lib/${i}-${BDBVER}.so
	${LN} -s -f ${i}-${BDBVER}.a ${PREFIX}/lib/${PORTNAME}/${i}.a
	${CHMOD} a-w ${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.so.0 \
		${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.a \
		${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.la
.endfor
	cd ${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER}; done
.if !defined(NOPORTDOCS)
.for i in api_reference/TCL
	${RM} -r -f ${DOCSDIR}/${i}
.endfor
.if !defined(WITH_JAVA)
	${RM} -r -f ${DOCSDIR}/java
.for i in gsg gsg_db_rep gsg_txn
	${RM} -r -f ${DOCSDIR}/${i}/JAVA
.endfor
.endif
.if !defined(WITH_SQL)
	${RM} -r -f ${DOCSDIR}/bdb-sql
.endif
.endif

.include <bsd.port.post.mk>
