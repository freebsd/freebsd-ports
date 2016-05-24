# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	db5
PORTVERSION=	5.3.28
PORTREVISION=	4
CATEGORIES=	databases java
MASTER_SITES=	http://download.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
#
# the distfiles aren't named db5-* but db-*:
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Oracle Berkeley DB, revision ${BDBVER}

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
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
PLIST_SUB=	BDBMAJ=${BDBMAJ} BDBVER=${BDBVER}
MAKE_ARGS+=	docdir=${DOCSDIR}
CFLAGS+=	-Wall -Wextra

OPTIONS_DEFINE=	CRYPTO L10N SQL JAVA DOCS TCL
# WARNING: DO NOT ADD TCL TO OPTIONS:
# On FreeBSD 10.3 this causes a heap of warnings of the following kind
# and is deemed unsafe.
# ./lang/tcl/tcl_*.c:*:*: warning: the value of the size argument in 'strncat' is too large, might lead to a buffer overflow [-Wstrncat-size]
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
# db5 is incompatible with openjdk8 and causes IllegalArgument
# exceptions during build
JAVA_VARS=		DBLIBS+=libdb_java JAVA_VERSION="1.6 1.7"
JAVA_CONFIGURE_ENABLE=	java
JAVA_CPPFLAGS=		-I"${JAVA_HOME}/include"
JAVA_CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}" JAVACFLAGS="-Xlint:unchecked"
TCL_CONFIGURE_ENABLE=	tcl
TCL_USES=		tcl:85+
TCL_CONFIGURE_WITH=	tcl=${TCL_LIBDIR}
TCL_VARS=		DBLIBS+=libdb_tcl
DOCS_INSTALL_TARGET=	install_docs

.include <bsd.port.options.mk>

.if ${ARCH} == "aarch64" || ${ARCH:Marmv6*}
# db5 uses a deprecated instruction for mutexes on ARM, fbsd bug#197227
# and also bug#205001
CONFIGURE_ARGS+=	--enable-posixmutexes
.endif

post-patch:
	${REINPLACE_CMD} -e '/^DOCLIST/{s/csharp//;}' ${WRKSRC}/../dist/Makefile.in
	${REINPLACE_CMD} -Ee 's/[[:<:]]atomic_init[[:>:]]/db_atomic_init/g' ${WRKSRC}/../src/mp/mp* ${WRKSRC}/../src/mutex/mut_*

post-install:
.for i in ${DBLIBS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.so.0
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${PORTNAME}/${i}-${BDBMAJ}.so ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib/${i}-${BDBVER}.so
	${LN} -s -f ${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib/${i}-${BDBMAJ}.so.0
	${LN} -s -f ${i}-${BDBVER}.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}.a
.endfor
	cd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; \
		       ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBMAJ} ; done
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

.include <bsd.port.mk>
