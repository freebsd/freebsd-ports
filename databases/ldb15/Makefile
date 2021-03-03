# $FreeBSD$

PORTNAME=		ldb
PORTVERSION=		1.5.6
PORTREVISION=		1
PORTEPOCH=		0
CATEGORIES=		databases
MASTER_SITES=		SAMBA
PKGNAMESUFFIX?=		15

MAINTAINER=		timur@FreeBSD.org
COMMENT=		LDAP-like embedded database

LICENSE=		GPLv3+

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

BUILD_DEPENDS=		${LDB_DEPENDS}
RUN_DEPENDS=		${LDB_DEPENDS}

LDB_DEPENDS=		talloc>=2.2.0:devel/talloc \
			tevent>=0.10.0:devel/tevent \
			tdb>=1.4.0:databases/tdb \
			lmdb>=0.9.23:databases/lmdb \
			cmocka>=1.1.3:sysutils/cmocka \
			popt>=0:devel/popt

CONFLICTS_INSTALL=	ldb-1.1.* ldb1[2-46]-1.*

#FLAVORS=		default nopython
#nopython_PKGNAMESUFFIX=	-nopython
#nopython_CONFLICTS=	ldb
#default_CONFLICTS=	ldb-nopython

USES=			compiler gettext-runtime pkgconfig waf
USE_LDCONFIG=		yes
WAF_CMD=		${BUILD_WRKSRC}/buildtools/bin/waf
CONFIGURE_LOG=		${BUILD_WRKSRC}/bin/config.log

USE_OPENLDAP=		yes
PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--bundled-libraries=!talloc,!tevent,!tdb,!popt,!cmocka \
			--with-modulesdir=${PREFIX}/lib/shared-modules \
			--with-privatelibdir=${PREFIX}/lib/ldb \
			--mandir=${MANPREFIX}/man \
			--with-openldap=${LOCALBASE} \
			--disable-rpath \
			--without-gettext

OPTIONS_DEFINE=		MANPAGES DEBUG
MANPAGES_DESC=		Build and install manpages (requires textproc/docbook-xsl)

DEBUG_CONFIGURE_ON=	--verbose --enable-debug
DEBUG_MAKE_ARGS=	--verbose
DEBUG_FLAGS=		-g -ggdb3 -O0

.include <bsd.port.options.mk>

LDB_BINS=		bin/ldbedit \
			bin/ldbmodify \
			bin/ldbadd \
			bin/ldbdel \
			bin/ldbsearch \
			bin/ldbrename

LDB_LIBS=		lib/libldb.so \
			lib/libldb.so.1 \
			lib/ldb/libldb-tdb-int.so \
			lib/ldb/libldb-tdb-err-map.so \
			lib/ldb/libldb-key-value.so \
			lib/ldb/libldb-cmdline.so \
			lib/shared-modules/ldb/skel.so \
			lib/shared-modules/ldb/server_sort.so \
			lib/shared-modules/ldb/sample.so \
			lib/shared-modules/ldb/rdn_name.so \
			lib/shared-modules/ldb/paged_searches.so \
			lib/shared-modules/ldb/ldb.so \
			lib/shared-modules/ldb/ldap.so \
			lib/shared-modules/ldb/asq.so \
			lib/shared-modules/ldb/tdb.so
# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != mips && ${ARCH} != powerpc && ${ARCH} != powerpcspe
LDB_LIBS+=		lib/ldb/libldb-mdb-int.so \
			lib/shared-modules/ldb/mdb.so
.endif

PLIST_FILES=		include/ldb_version.h \
			include/ldb_handlers.h \
			include/ldb_errors.h \
			include/ldb.h \
			include/ldb_module.h \
			${LDB_BINS} \
			${LDB_LIBS} \
			${PKGCONFIGDIR}/ldb.pc

.if defined(NO_PYTHON)
USES+=			python:build,test
CONFIGURE_ARGS+=	--disable-python
.else
USES+=			python:3.4+

PLIST_FILES+=		include/pyldb.h \
			lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so \
			lib/libpyldb-util${PYTHON_EXT_SUFFIX}.so.1 \
			${PYTHON_SITELIBDIR}/ldb${PYTHON_EXT_SUFFIX}.so \
			${PYTHON_SITELIBDIR}/_ldb_text.py \
			${PKGCONFIGDIR}/pyldb-util${PYTHON_EXT_SUFFIX}.pc
.endif

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ENV+=		XSLTPROC="true"
.else
BUILD_DEPENDS+=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
.endif
CONFIGURE_ENV+=		CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

# No fancy color error messages
.if ${COMPILER_TYPE} == "clang"
CFLAGS+=		-fno-color-diagnostics
.endif
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

LDB_MAN1=		man/man1/ldbadd.1.gz \
			man/man1/ldbdel.1.gz \
			man/man1/ldbedit.1.gz \
			man/man1/ldbmodify.1.gz \
			man/man1/ldbrename.1.gz \
			man/man1/ldbsearch.1.gz

LDB_MAN3=		man/man3/ldb.3.gz

PLIST_FILES+=		${LDB_MAN1} ${LDB_MAN3}

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
			${INSTALL_MAN} ${FILESDIR}/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.endfor

post-install:
.for lib in ${LDB_BINS} ${LDB_LIBS}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${lib}
.endfor
.if !defined(NO_PYTHON)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpyldb-util*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ldb*.so
.endif

.include <bsd.port.post.mk>
