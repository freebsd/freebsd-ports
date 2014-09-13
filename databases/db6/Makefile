# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	db6
PORTVERSION=	6.1.19
CATEGORIES=	databases java
MASTER_SITES=	http://download.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
# the distfiles aren't named db6-* but db-*:
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Oracle Berkeley DB, revision ${BDBVER}

LICENSE=	AGPLv3

BDBVER=		${PORTVERSION:R}
BDBMAJ=		${BDBVER:R}
CONFIGURE_ARGS=	--enable-cxx --enable-stl \
		--enable-compat185 --enable-dump185 \
		--disable-tcl \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME}
CONFIGURE_SCRIPT=	../dist/configure
GNU_CONFIGURE=	yes
USES=		gmake libtool
INSTALL_TARGET=	install_include install_lib install_utilities
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
USE_LDCONFIG=	yes
PLIST_SUB=	BDBMAJ=${BDBMAJ} BDBVER=${BDBVER}
MAKE_ARGS+=	docdir=${DOCSDIR}

OPTIONS_DEFINE=	CRYPTO L10N SQL JAVA DOCS
OPTIONS_DEFAULT=CRYPTO
CRYPTO_DESC=	Cryptography support
L10N_DESC=	Localization support (EXPERIMENTAL)
SQL_DESC=	Enable SQL API (EXPERIMENTAL)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=install_docs
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MSQL}
CONFIGURE_ARGS+=	--enable-sql_codegen --enable-sql
PLIST_SUB+=	SQL=""
libdb_sql=	libdb_sql
.else
PLIST_SUB+=	SQL="@comment "
libdb_sql=
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
CONFIGURE_ARGS+=	--enable-java
CPPFLAGS+=	"-I${JAVA_HOME}/include"
CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}"
PLIST_SUB+=	JAVA=""
libdb_java=	libdb_java
.else
PLIST_SUB+=	JAVA="@comment "
libdb_java=
.endif

.if ${PORT_OPTIONS:MCRYPTO}
CONFIGURE_ARGS+=	--with-cryptography=yes
.else
CONFIGURE_ARGS+=	--with-cryptography=no
.endif

.if ${PORT_OPTIONS:ML10N}
CONFIGURE_ARGS+=	--enable-localization
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-umrw
.endif

post-patch:
	${REINPLACE_CMD} -e '/^DOCLIST/{s/csharp//;}' ${WRKSRC}/../dist/Makefile.in
	${REINPLACE_CMD} -Ee 's/[[:<:]]atomic_init[[:>:]]/db_atomic_init/g' \
	    ${WRKSRC}/../src/mp/mp* ${WRKSRC}/../src/mutex/mut_* \
	    ${WRKSRC}/../src/dbinc/atomic.h

post-install:
.for i in libdb libdb_cxx libdb_stl ${libdb_sql} ${libdb_java}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.so
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}.a
.endfor
	cd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; done
.if ${PORT_OPTIONS:MDOCS}
.for i in api_reference/TCL
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/${i}
.endfor
.if empty(PORT_OPTIONS:MJAVA)
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/java
.for i in gsg gsg_db_rep gsg_txn
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/${i}/JAVA
.endfor
.endif
.if empty(PORT_OPTIONS:MSQL)
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/bdb-sql
.endif
.endif

.include <bsd.port.mk>
