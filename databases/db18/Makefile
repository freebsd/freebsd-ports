PORTNAME=	db18
PORTVERSION=	18.1.40
CATEGORIES=	databases java
MASTER_SITES=	https://github.com/yasuhirokimura/${PORTNAME}/releases/download/${PORTVERSION}/
PKGNAMEPREFIX?=
#
# the distfiles aren't named db18-* but db-*:
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Oracle Berkeley DB, Release ${BDBVER}

LICENSE=	AGPLv3 BSD3CLAUSE UPL10
LICENSE_COMB=	multi
LICENSE_NAME_UPL10=	The Universal Permissive License (UPL), Version 1.0
LICENSE_FILE_UPL10=	${WRKSRC}/../EXAMPLES-LICENSE
LICENSE_FILE=	${WRKSRC}/../LICENSE
LICENSE_PERMS_UPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_mips64=	no usable MUTEX implementation, assy works only for MIPS32, POSIX mutexes are unshared

USES=		gmake libtool ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--bindir=${PREFIX}/bin/${PORTNAME} \
			--enable-compat185 \
			--enable-cxx \
			--enable-dbm \
			--enable-dump185 \
			--enable-stl \
			--includedir=${PREFIX}/include/${PORTNAME} \
			--libdir=${PREFIX}/lib/${PORTNAME}

MAKE_ARGS+=	docdir=${DOCSDIR}
INSTALL_TARGET=	install_include install_lib install_utilities

CFLAGS+=	-I${OPENSSLINC}
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

PLIST_SUB=	BDBMAJ=${BDBMAJ} \
		BDBVER=${BDBVER}
PORTDOCS=	*

OPTIONS_DEFINE=		CRYPTO DEBUG DOCS JAVA L10N TCL
OPTIONS_DEFAULT=	CRYPTO
OPTIONS_SUB=		yes

CRYPTO_DESC=	Cryptography support
L10N_DESC=	Localization support (EXPERIMENTAL)

CRYPTO_CONFIGURE_WITH=	cryptography=yes
DEBUG_CONFIGURE_ENABLE=	debug umrw
DOCS_INSTALL_TARGET=	install_docs
JAVA_USE=		java
JAVA_CONFIGURE_ENABLE=	java
JAVA_CONFIGURE_ENV=	JAR="${JAR}" \
			JAVA="${JAVA}" \
			JAVAC="${JAVAC}"
JAVA_CPPFLAGS=		-I"${JAVA_HOME}/include"
JAVA_VARS=		DBLIBS+=libdb_java \
			JAVA_VERSION="7+"
L10N_CONFIGURE_ENABLE=	localization
TCL_USES=		tcl
TCL_CONFIGURE_ENABLE=	tcl
TCL_CONFIGURE_WITH=	tcl=${TCL_LIBDIR}
TCL_VARS=		DBLIBS+=libdb_tcl

BDBVER=		${PORTVERSION:R}
BDBMAJ=		${BDBVER:R}

DBLIBS=		libdb libdb_cxx libdb_stl

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
CONFIGURE_ARGS+=	--with-mutex=POSIX/pthreads
.endif

post-install:
.for i in ${DBLIBS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}-${BDBVER}.so
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so ${STAGEDIR}${PREFIX}/lib/${i}-${BDBMAJ}.so
	${LN} -s -f ${i}-${BDBVER}.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${i}.a
.endfor
	cd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; done

post-install-JAVA-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}/java
.for i in gsg gsg_db_rep gsg_txn
	${RM} -r ${STAGEDIR}${DOCSDIR}/${i}/JAVA
.endfor

post-install-TCL-on:
	echo "package ifneeded Db_tcl ${BDBVER} \
	      [list load [file join $$dir libdb_tcl-${BDBVER}.so]] \
	     " > ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/pkgIndex.tcl

post-install-TCL-off:
.for i in api_reference/TCL
	${RM} -r ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
