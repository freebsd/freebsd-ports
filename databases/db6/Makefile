# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	db6
PORTVERSION=	6.2.23
CATEGORIES=	databases java
MASTER_SITES=	http://download.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
#
# the distfiles aren't named db6-* but db-*:
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Oracle Berkeley DB, revision ${BDBVER}

LICENSE=	AGPLv3

BDBVER=		${PORTVERSION:R}
BDBMAJ=		${BDBVER:R}
CONFIGURE_ARGS=	--enable-cxx --enable-stl \
		--enable-compat185 --enable-dump185 \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME}
CONFIGURE_SCRIPT=	../dist/configure
GNU_CONFIGURE=	yes
USES=		gmake libtool
INSTALL_TARGET=	install_include install_lib install_utilities
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
PLIST_SUB=	BDBMAJ=${BDBMAJ} BDBVER=${BDBVER}
MAKE_ARGS+=	docdir=${DOCSDIR}

OPTIONS_DEFINE=	CRYPTO L10N SQL JAVA TCL DOCS
OPTIONS_DEFAULT=CRYPTO
OPTIONS_SUB=	yes
CRYPTO_DESC=	Cryptography support
L10N_DESC=	Localization support (EXPERIMENTAL)
SQL_DESC=	Enable SQL API (EXPERIMENTAL)

PORTDOCS=	*

DBLIBS=	libdb libdb_cxx libdb_stl

DEBUG_CONFIGURE_ENABLE=	debug umrw
CRYPTO_CONFIGURE_WITH=	cryptography=yes
L10N_CONFIGURE_ENABLE=	localization
SQL_CONFIGURE_ENABLE=	sql sql_codegen
SQL_VARS=		DBLIBS+=libdb_sql
JAVA_USE=		java
JAVA_VARS=		DBLIBS+=libdb_java JAVA_VERSION=1.6+
JAVA_CONFIGURE_ENABLE=	java
JAVA_CPPFLAGS=		-I"${JAVA_HOME}/include"
JAVA_CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}"
TCL_CONFIGURE_ENABLE=	tcl
TCL_USES=		tcl:85+
TCL_CONFIGURE_WITH=	tcl=${TCL_LIBDIR}
TCL_VARS=		DBLIBS+=libdb_tcl
DOCS_INSTALL_TARGET=	install_docs

.include <bsd.port.options.mk>

.if ${ARCH} == "aarch64" || ${ARCH:Marmv6*}
# db6 uses a deprecated instruction for mutexes on ARM, fbsd bug#197227
# and also bug #205001
CONFIGURE_ARGS+=	--enable-posixmutexes
.endif

post-patch:
	${REINPLACE_CMD} -e '/^DOCLIST/{s/csharp//;}' ${WRKSRC}/../dist/Makefile.in
	${REINPLACE_CMD} -Ee 's/[[:<:]]atomic_init[[:>:]]/db_atomic_init/g' \
	    ${WRKSRC}/../src/mp/mp* ${WRKSRC}/../src/mutex/mut_* \
	    ${WRKSRC}/../src/dbinc/atomic.h
	${REINPLACE_CMD} -e 's/%%BDBVER%%/${BDBVER}/' ${WRKSRC}/../lang/sql/upgrade61.sh

post-install:
.for i in ${DBLIBS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.so
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}.a
.endfor
	cd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; done
.if empty(PORT_OPTIONS:MJAVA)
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/java
.for i in gsg gsg_db_rep gsg_txn
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/${i}/JAVA
.endfor
.endif
.if empty(PORT_OPTIONS:MSQL)
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/bdb-sql
.endif
.if !empty(PORT_OPTIONS:MTCL)
	echo "package ifneeded Db_tcl ${BDBVER} \
	      [list load [file join $$dir libdb_tcl-${BDBVER}.so]] \
	     " > ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/pkgIndex.tcl
.else
.for i in api_reference/TCL
	${RM} -r -f ${STAGEDIR}${DOCSDIR}/${i}
.endfor
.endif

post-install-SQL-on:
	${INSTALL_SCRIPT} ${WRKSRC}/../lang/sql/upgrade61.sh \
	    ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-upgrade61.sh

.include <bsd.port.mk>
