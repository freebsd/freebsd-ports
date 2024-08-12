PORTNAME=	ldb
PORTVERSION=	2.5.3
CATEGORIES=	databases
MASTER_SITES=	SAMBA
PKGNAMESUFFIX?=	25

MAINTAINER=	kiwi@oav.net
COMMENT=	LDAP-like embedded database
WWW=		https://ldb.samba.org/

LICENSE=	GPLv3+

IGNORE_NONTHREAD_PYTHON=	needs port lang/python${PYTHON_SUFFIX} to be \
				build with THREADS support

LDB_DEPENDS=	talloc>=2.2.0:devel/talloc tevent>=0.10.0:devel/tevent \
		tdb>=1.4.0:databases/tdb lmdb>=0.9.23:databases/lmdb \
		popt>=0:devel/popt
BUILD_DEPENDS=	${LDB_DEPENDS} \
		cmocka>=1.1.3:sysutils/cmocka
TEST_DEPENDS=	${LDB_DEPENDS} \
		cmocka>=1.1.3:sysutils/cmocka
RUN_DEPENDS=	${LDB_DEPENDS}

USES=		compiler ldap localbase:ldflags pkgconfig waf

CONFLICTS_INSTALL=	ldb[0-9][0-9] # include/ldb.h

USE_LDCONFIG=	yes
WAF_CMD=	${BUILD_WRKSRC}/buildtools/bin/waf
CONFIGURE_LOG=	${BUILD_WRKSRC}/bin/config.log

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig
PLIST_SUB+=	PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--bundled-libraries=!talloc,!tevent,!tdb,!popt,!cmocka \
			--disable-rpath \
			--with-modulesdir=${PREFIX}/lib/shared-modules \
			--with-openldap=${LOCALBASE} \
			--with-privatelibdir=${PREFIX}/lib/ldb \
			--without-gettext

OPTIONS_DEFINE=	DEBUG MANPAGES PYTHON3
MANPAGES_DESC=	Build and install manpages (requires textproc/docbook-xsl)

DEBUG_CONFIGURE_ON=	--enable-debug \
			--verbose
DEBUG_MAKE_ARGS=	--verbose
DEBUG_FLAGS=		-g -ggdb3 -O0

.include <bsd.port.options.mk>

LDB_BINS=	bin/ldbedit bin/ldbmodify bin/ldbadd bin/ldbdel bin/ldbsearch \
		bin/ldbrename

LDB_LIBS=	lib/libldb.so lib/libldb.so.2 lib/ldb/libldb-tdb-int.so \
		lib/ldb/libldb-tdb-err-map.so lib/ldb/libldb-key-value.so \
		lib/ldb/libldb-cmdline.so lib/shared-modules/ldb/skel.so \
		lib/shared-modules/ldb/server_sort.so \
		lib/shared-modules/ldb/sample.so \
		lib/shared-modules/ldb/rdn_name.so \
		lib/shared-modules/ldb/paged_searches.so \
		lib/shared-modules/ldb/ldb.so lib/shared-modules/ldb/ldap.so \
		lib/shared-modules/ldb/asq.so lib/shared-modules/ldb/tdb.so
# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != mips && \
	${ARCH} != powerpc && ${ARCH} != powerpcspe
LDB_LIBS+=	lib/ldb/libldb-mdb-int.so lib/shared-modules/ldb/mdb.so
.endif

PLIST_FILES=	${LDB_BINS} \
		${LDB_LIBS} \
		${PKGCONFIGDIR}/ldb.pc \
		include/ldb.h \
		include/ldb_errors.h \
		include/ldb_handlers.h \
		include/ldb_module.h \
		include/ldb_version.h

.include <bsd.port.pre.mk>

# Some symbols in ldb's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

.if !${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ENV+=	XSLTPROC="true"
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
.endif

.if !${PORT_OPTIONS:MPYTHON3} || defined(NO_PYTHON)
USES+=			python:build,test
CONFIGURE_ARGS+=	--disable-python
.else
USES+=			gettext-runtime python

PLIST_FILES+=	${PKGCONFIGDIR}/pyldb-util${PYTHON_EXT_SUFFIX}.pc \
		${PYTHON_SITELIBDIR}/_ldb_text.py \
		${PYTHON_SITELIBDIR}/ldb${PYTHON_EXT_SUFFIX}.so \
		include/pyldb.h \
		lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so \
		lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so.2
.endif

# No fancy color error messages
.if ${COMPILER_TYPE} == "clang"
CFLAGS+=	-fno-color-diagnostics
.endif
CONFIGURE_ENV+=	NOCOLOR=yes
MAKE_ENV+=	NOCOLOR=yes

LDB_MAN1=	share/man/man1/ldbadd.1.gz \
		share/man/man1/ldbdel.1.gz \
		share/man/man1/ldbedit.1.gz \
		share/man/man1/ldbmodify.1.gz \
		share/man/man1/ldbrename.1.gz \
		share/man/man1/ldbsearch.1.gz

LDB_MAN3=	share/man/man3/ldb.3.gz

PLIST_FILES+=	${LDB_MAN1} \
		${LDB_MAN3}

post-patch:
			@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
				${BUILD_WRKSRC}/wscript

# Use threading (or multiprocessing) but not thread (renamed in python 3+).
pre-configure:
			@if ! ${PYTHON_CMD} -c "import multiprocessing;" 2>/dev/null; then \
				${ECHO_CMD}; \
				${ECHO_MSG} "===>  ${PKGNAME} "${IGNORE_NONTHREAD_PYTHON:Q}.; \
				${ECHO_CMD}; \
				${FALSE}; \
			fi

pre-build-MANPAGES-off:
			-${MKDIR} ${BUILD_WRKSRC}/bin/default/man
.for man in ${LDB_MAN1} ${LDB_MAN3}
			${INSTALL_MAN} ${FILESDIR}/man/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.endfor

post-install:
.for lib in ${LDB_BINS} ${LDB_LIBS}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${lib}
.endfor
.if ${PORT_OPTIONS:MPYTHON3} && !defined(NO_PYTHON)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ldb${PYTHON_EXT_SUFFIX}.so
.endif

.include <bsd.port.post.mk>
