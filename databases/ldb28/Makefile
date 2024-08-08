PORTNAME=	ldb
PORTVERSION=	2.8.1
CATEGORIES=	databases
MASTER_SITES=	SAMBA
PKGNAMESUFFIX?=	${PORTVERSION:C/([[:digit:]]+)[.]([[:digit:]]+).*/\1\2/}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	LDAP-like embedded database
WWW=		https://ldb.samba.org/

LICENSE=	GPLv3+

IGNORE_NONTHREAD_PYTHON=	needs port lang/python${PYTHON_SUFFIX} to be \
				build with THREADS support

BUILD_DEPENDS=	${_LDB_DEPENDS} \
		cmocka>=1.1.3:sysutils/cmocka
RUN_DEPENDS=	${_LDB_DEPENDS}
TEST_DEPENDS=	${_LDB_DEPENDS} \
		cmocka>=1.1.3:sysutils/cmocka

USES=		compiler ldap localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

HAS_CONFIGURE=		yes
CONFIGURE_LOG=		${BUILD_WRKSRC}/bin/config.log
PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS+=	--bundled-libraries=!talloc,!tevent,!tdb,!popt,!cmocka \
			--disable-rpath \
			--with-modulesdir=${PREFIX}/lib/shared-modules \
			--with-openldap=${LOCALBASE} \
			--with-privatelibdir=${PREFIX}/lib/ldb \
			--without-gettext
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes
CFLAGS+=		${_CFLAGS_${COMPILER_TYPE}}
DEBUG_FLAGS=		-g -ggdb3 -O0
# Some symbols in ldb's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=		-Wl,--undefined-version

CONFLICTS_INSTALL=	ldb[0-9][0-9] # include/ldb.h

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	${_LDB_BINS} \
		${_LDB_LIBS_64} \
		${_LDB_LIBS} \
		${_LDB_MAN1} \
		${_LDB_MAN3} \
		${PKGCONFIGDIR}/ldb.pc \
		include/ldb.h \
		include/ldb_errors.h \
		include/ldb_handlers.h \
		include/ldb_module.h \
		include/ldb_version.h

PLIST_SUB+=	PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

OPTIONS_DEFINE=		MANPAGES PYTHON3
OPTIONS_DEFAULT=	PYTHON3
MANPAGES_DESC=		Build and install manpages (requires textproc/docbook-xsl)

MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="true"

PYTHON3_USES=		gettext-runtime python
PYTHON3_USES_OFF=	python:build,test
PYTHON3_CONFIGURE_OFF=	--disable-python
PYTHON3_PLIST_FILES=	${PKGCONFIGDIR}/pyldb-util${PYTHON_EXT_SUFFIX}.pc \
			${PYTHON_SITELIBDIR}/_ldb_text.py \
			${PYTHON_SITELIBDIR}/ldb${PYTHON_EXT_SUFFIX}.so \
			include/pyldb.h \
			lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so \
			lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so.2

# No fancy color error messages
_CFLAGS_clang=	-fno-color-diagnostics

_LDB_DEPENDS=	talloc>=2.2.0:devel/talloc tevent>=0.10.0:devel/tevent \
		tdb>=1.4.0:databases/tdb lmdb>=0.9.23:databases/lmdb \
		popt>=0:devel/popt
_LDB_BINS=	bin/ldbedit bin/ldbmodify bin/ldbadd bin/ldbdel bin/ldbsearch \
		bin/ldbrename
_LDB_LIBS=	lib/libldb.so lib/libldb.so.2 lib/ldb/libldb-tdb-int.so \
		lib/ldb/libldb-tdb-err-map.so lib/ldb/libldb-key-value.so \
		lib/ldb/libldb-cmdline.so lib/shared-modules/ldb/skel.so \
		lib/shared-modules/ldb/server_sort.so \
		lib/shared-modules/ldb/sample.so \
		lib/shared-modules/ldb/rdn_name.so \
		lib/shared-modules/ldb/paged_searches.so \
		lib/shared-modules/ldb/ldb.so lib/shared-modules/ldb/ldap.so \
		lib/shared-modules/ldb/asq.so lib/shared-modules/ldb/tdb.so
_LDB_MAN1=	share/man/man1/ldbadd.1.gz share/man/man1/ldbdel.1.gz \
		share/man/man1/ldbedit.1.gz share/man/man1/ldbmodify.1.gz \
		share/man/man1/ldbrename.1.gz share/man/man1/ldbsearch.1.gz
_LDB_MAN3=	share/man/man3/ldb.3.gz

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug \
			--verbose
.endif

# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != mips && \
	${ARCH} != powerpc && ${ARCH} != powerpcspe
_LDB_LIBS_64=	lib/ldb/libldb-mdb-int.so lib/shared-modules/ldb/mdb.so
.endif

.if defined(NO_PYTHON)
WARNING+=	"${PKGNAME} does not support NO_PYTHON anymore; use option PYTHON3 instead"
.endif

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
			${MKDIR} ${BUILD_WRKSRC}/bin/default/man
.for man in ${_LDB_MAN1} ${_LDB_MAN3}
			${INSTALL_MAN} ${FILESDIR}/man/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.endfor

post-install:
.for lib in ${_LDB_BINS} ${_LDB_LIBS} ${_LDB_LIBS_64}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${lib}
.endfor

post-install-PYTHON3-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ldb${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
