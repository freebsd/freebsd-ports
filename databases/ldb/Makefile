# $FreeBSD$

PORTNAME=		ldb
PORTVERSION=		1.1.16
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		LDAP-like embedded database

LICENSE=		GPLv3

CONFLICTS=		*samba3[0-4]-3.*

USES=			compiler pkgconfig
USE_PYTHON_BUILD=	2
USE_LDCONFIG=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_LOG=		bin/config.log

USE_OPENLDAP=		yes

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--mandir=${MANPREFIX}/man \
			--infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR}
# Support staging
DESTDIRNAME=		--destdir

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=		talloc>=2.0.8:${PORTSDIR}/devel/talloc \
			tevent>=0.9.17:${PORTSDIR}/devel/tevent \
			tdb>=1.2.11:${PORTSDIR}/databases/tdb \
			popt>=0:${PORTSDIR}/devel/popt
RUN_DEPENDS:=		${BUILD_DEPENDS}

CONFIGURE_ARGS+=	--bundled-libraries=!talloc,!tevent,!tdb,!popt \
			--with-modulesdir=${PREFIX}/lib/shared-modules \
			--with-privatelibdir=${PREFIX}/lib/ldb

.if ! ${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ENV+=		XSLTPROC="true"
.else
BUILD_DEPENDS+=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
			xsltproc:${PORTSDIR}/textproc/libxslt
.endif

PLIST_DIRSTRY=		lib/ldb \
			lib/shared-modules/ldb \
			lib/shared-modules

PLIST_FILES=		bin/ldbedit \
			bin/ldbmodify \
			bin/ldbadd \
			bin/ldbdel \
			bin/ldbsearch \
			bin/ldbrename \
			include/ldb_version.h \
			include/ldb_handlers.h \
			include/ldb_errors.h \
			include/ldb.h \
			include/ldb_module.h \
			lib/libldb.so \
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
			lib/shared-modules/ldb/tdb.so \
			%%PKGCONFIGDIR%%/ldb.pc

# No fancy color error messages
.if ${COMPILER_TYPE} == "clang"
CFLAGS+=		-fno-color-diagnostics
.endif
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

.if !defined(DISABLE_MAKE_JOBS) && !defined(MAKE_JOBS_UNSAFE)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS+=		--jobs=${MAKE_JOBS_NUMBER}
.endif

USE_PYTHON_RUN=		yes

PLIST_FILES+=		include/pyldb.h \
			lib/libpyldb-util.so \
			lib/libpyldb-util.so.1 \
			%%PYTHON_SITELIBDIR%%/ldb.so \
			%%PKGCONFIGDIR%%/pyldb-util.pc
PLIST_DIRSTRY+=		%%PYTHON_SITELIBDIR%% \
			%%PYTHON_LIBDIR%%

LDB_MAN1=		man/man1/ldbadd.1.gz \
			man/man1/ldbdel.1.gz \
			man/man1/ldbedit.1.gz \
			man/man1/ldbmodify.1.gz \
			man/man1/ldbrename.1.gz \
			man/man1/ldbsearch.1.gz

LDB_MAN3=		man/man3/ldb.3.gz

PLIST_FILES+=		${LDB_MAN1} ${LDB_MAN3}

CONFIGURE_TARGET=	configure
ALL_TARGET=		build
INSTALL_TARGET=		install

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

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

do-configure:
			@(cd ${CONFIGURE_WRKSRC} && \
			    ${SET_LATE_CONFIGURE_ARGS} \
				if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
					CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
					LDFLAGS="${LDFLAGS}" \
					INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
					INSTALL_DATA="${INSTALL_DATA}" \
					INSTALL_LIB="${INSTALL_LIB}" \
					INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
					INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
					${CONFIGURE_ENV} ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/${WAF_TOOL} ${CONFIGURE_ARGS} ${CONFIGURE_TARGET}; then \
						${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
						(${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
						${FALSE}; \
				fi)

pre-build:
.if ! ${PORT_OPTIONS:MMANPAGES}
			-${MKDIR} ${BUILD_WRKSRC}/bin/default/man
.	for man in ${LDB_MAN1} ${LDB_MAN3}
			${INSTALL_MAN} ${FILESDIR}/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.	endfor
.endif

do-build:
			@(cd ${BUILD_WRKSRC}; \
			if ! ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${BUILD_WRKSRC}/${WAF_TOOL} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
				if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
					${ECHO_MSG} "===> Compilation failed unexpectedly."; \
					(${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
				fi; \
			${FALSE}; \
			fi)

do-install:
			@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_WRKSRC}/${WAF_TOOL} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
