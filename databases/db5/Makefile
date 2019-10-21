# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	db5
PORTVERSION=	5.3.28
PORTREVISION=	7
CATEGORIES=	databases java
MASTER_SITES=	https://download.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
#
# the distfiles aren't named db5-* but db-*:
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Oracle Berkeley DB, revision ${BDBVER}

LICENSE=	SLEEPYCAT
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	Sleepycat
LICENSE_FILE=	${WRKSRC}/../LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BDBVER=		${PORTVERSION:R}
BDBMAJ=		${BDBVER:R}
CONFIGURE_ARGS=	--enable-cxx --enable-stl --enable-dbm \
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
CFLAGS+=	-Wall -Wextra

OPTIONS_DEFINE=	CRYPTO DEBUG L10N SQL JAVA TCL DOCS
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
JAVA_VARS=		DBLIBS+=libdb_java JAVA_VERSION="1.7"
JAVA_CONFIGURE_ENABLE=	java
JAVA_CPPFLAGS=		-I"${JAVA_HOME}/include"
JAVA_CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}" JAVACFLAGS="-Xlint:unchecked"
TCL_CONFIGURE_ENABLE=	tcl
TCL_USES=		tcl
TCL_CONFIGURE_WITH=	tcl=${TCL_LIBDIR}
TCL_VARS=		DBLIBS+=libdb_tcl
DOCS_INSTALL_TARGET=	install_docs

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH:Marmv*}
# db5 uses a deprecated instruction for mutexes on ARM, fbsd bug#197227
# and also bug#205001
CONFIGURE_ARGS+=	--enable-posixmutexes
# force POSIX mutexes - the OS supports PTHREAD_PROCESS_SHARED
CONFIGURE_ARGS+=	--with-mutex=POSIX/pthreads
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

post-install-JAVA-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}/java
.for i in gsg gsg_db_rep gsg_txn
	${RM} -r ${STAGEDIR}${DOCSDIR}/${i}/JAVA
.endfor

post-install-SQL-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}/bdb-sql

post-install-TCL-on:
	echo "package ifneeded Db_tcl ${BDBVER} \
	      [list load [file join $$dir libdb_tcl-${BDBVER}.so]] \
	     " > ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/pkgIndex.tcl

post-install-TCL-off:
.for i in api_reference/TCL
	${RM} -r ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
