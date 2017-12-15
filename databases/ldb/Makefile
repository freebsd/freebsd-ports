# $FreeBSD$

PORTNAME=		ldb
PORTVERSION=		1.1.29
PORTREVISION=		1
PORTEPOCH=		0
CATEGORIES=		databases
MASTER_SITES=		SAMBA

MAINTAINER=		timur@FreeBSD.org
COMMENT=		LDAP-like embedded database

LICENSE=		GPLv3

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

BUILD_DEPENDS=		${LDB_DEPENDS}
RUN_DEPENDS=		${LDB_DEPENDS}

LDB_DEPENDS=		talloc>=2.1.8:devel/talloc \
			tevent>=0.9.31:devel/tevent \
			tdb>=1.3.12,1:databases/tdb \
			popt>=0:devel/popt

CONFLICTS=		ldb1[23]-1.*

USES=			compiler pkgconfig waf
USE_LDCONFIG=		yes
WAF_CMD=		buildtools/bin/waf
CONFIGURE_LOG=		bin/config.log

USE_OPENLDAP=		yes
PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--bundled-libraries=!talloc,!tevent,!tdb,!popt \
			--with-modulesdir=${PREFIX}/lib/shared-modules \
			--with-privatelibdir=${PREFIX}/lib/ldb

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
			--infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR} \
			--disable-rpath \
			--without-gettext

OPTIONS_DEFINE=		MANPAGES
MANPAGES_DESC=		Build and install manpages (requires textproc/docbook-xsl)

.include <bsd.port.options.mk>

LDB_BINS=		bin/ldbedit \
			bin/ldbmodify \
			bin/ldbadd \
			bin/ldbdel \
			bin/ldbsearch \
			bin/ldbrename

LDB_LIBS=		lib/libldb.so \
			lib/libldb.so.1 \
			lib/ldb/libldb-cmdline.so \
			lib/shared-modules/ldb/asq.so \
			lib/shared-modules/ldb/ldap.so \
			lib/shared-modules/ldb/paged_results.so \
			lib/shared-modules/ldb/paged_searches.so \
			lib/shared-modules/ldb/rdn_name.so \
			lib/shared-modules/ldb/sample.so \
			lib/shared-modules/ldb/server_sort.so \
			lib/shared-modules/ldb/skel.so \
			lib/shared-modules/ldb/tdb.so

PLIST_FILES=		include/ldb_version.h \
			include/ldb_handlers.h \
			include/ldb_errors.h \
			include/ldb.h \
			include/ldb_module.h \
			${LDB_BINS} \
			${LDB_LIBS} \
			%%PKGCONFIGDIR%%/ldb.pc

.if defined(NO_PYTHON)
USES+=			python:2.7,build
#CONFIGURE_ARGS+=	--disable-python
.else
USES+=			python:2.7

PLIST_FILES+=		include/pyldb.h \
			lib/libpyldb-util.so \
			lib/libpyldb-util.so.1 \
			%%PYTHON_SITELIBDIR%%/ldb.so \
			%%PYTHON_SITELIBDIR%%/_ldb_text.py \
			%%PKGCONFIGDIR%%/pyldb-util.pc
.endif

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ENV+=		XSLTPROC="true"
.else
BUILD_DEPENDS+=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
.endif
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
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpyldb-util.so
			${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ldb.so
.else
.for file in		include/pyldb.h \
			lib/libpyldb-util.so \
			lib/libpyldb-util.so.1 \
			lib/ldb/libpytalloc-util.so.2
				${RM} ${STAGEDIR}${PREFIX}/${file}
.endfor
.for file in		${PYTHON_SITELIBDIR}/ldb.so \
			${PYTHON_SITELIBDIR}/_ldb_text.py \
			${PYTHON_SITELIBDIR}/_tdb_text.py \
			${PYTHON_SITELIBDIR}/_tevent.so \
			${PYTHON_SITELIBDIR}/talloc.so \
			${PYTHON_SITELIBDIR}/tdb.so \
			${PYTHON_SITELIBDIR}/tevent.py \
			${PKGCONFIGDIR}/pyldb-util.pc
				${RM} ${STAGEDIR}/${file}
.endfor
			${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
			${RMDIR} ${STAGEDIR}${PYTHON_LIBDIR}
.endif

.include <bsd.port.post.mk>
