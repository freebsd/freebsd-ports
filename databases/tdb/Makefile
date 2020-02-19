# $FreeBSD$

PORTNAME=		tdb
PORTVERSION=		1.4.2
PORTREVISION=		0
PORTEPOCH=		1
CATEGORIES=		databases
MASTER_SITES=		SAMBA

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Trivial Database

LICENSE=		GPLv3

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

CONFLICTS_INSTALL=	tdb1-*

#FLAVORS=		default nopython debug
#nopython_PKGNAMESUFFIX=	-nopython
#debug_PKGNAMESUFFIX=	-debug
#nopython_CONFLICTS=	tdb tdb-debug
#debug_CONFLICTS=	tdb tdb-nopython
#default_CONFLICTS=	tdb-nopython tdb-debug

USES=			compiler gettext-runtime pkgconfig waf 
USE_LDCONFIG=		yes
WAF_CMD=		buildtools/bin/waf
CONFIGURE_LOG=		bin/config.log

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
			--disable-rpath \
			--without-gettext

OPTIONS_DEFINE=		MANPAGES DEBUG
MANPAGES_DESC=		Build and install manpages (requires textproc/docbook-xsl)

DEBUG_CONFIGURE_ON=	--verbose --enable-debug
DEBUG_MAKE_ARGS=	--verbose
DEBUG_FLAGS=		-g -ggdb3 -O0 -DTDB_TRACE=1

.include <bsd.port.options.mk>

TDB_BINS=		bin/tdbbackup \
			bin/tdbdump \
			bin/tdbrestore \
			bin/tdbtool

PLIST_FILES+=		include/tdb.h \
			${TDB_BINS} \
			lib/libtdb.so \
			lib/libtdb.so.1 \
			${PKGCONFIGDIR}/tdb.pc


.if defined(NO_PYTHON)
USES+=			python:build,test
CONFIGURE_ARGS+=	--disable-python
.else
USES+=			python:3.4+

PLIST_FILES+=		${PYTHON_SITELIBDIR}/tdb.so \
			${PYTHON_SITELIBDIR}/_tdb_text.py
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

TDB_MAN8=		man/man8/tdbbackup.8.gz \
			man/man8/tdbdump.8.gz \
			man/man8/tdbrestore.8.gz \
			man/man8/tdbtool.8.gz

PLIST_FILES+=		${TDB_MAN8}

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
.for man in ${TDB_MAN8}
			${INSTALL_MAN} ${FILESDIR}/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.endfor

post-install:
.for lib in ${TDB_BINS} lib/libtdb.so
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/${lib}
.endfor
.if !defined(NO_PYTHON)
			${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tdb.so
.endif

.include <bsd.port.post.mk>
