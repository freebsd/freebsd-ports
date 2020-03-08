# $FreeBSD$

PORTNAME=		ntdb
PORTVERSION=		1.0
PORTREVISION=		2
PORTEPOCH=		0
CATEGORIES=		databases
MASTER_SITES=		SAMBA/tdb

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Not so Trivial DataBase

LICENSE=		GPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

CONFLICTS=

USES=			compiler pkgconfig waf
USE_LDCONFIG=		yes
WAF_CMD=		buildtools/bin/waf
CONFIGURE_LOG=		bin/config.log

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
			--infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR} \
			--disable-rpath \
			--without-gettext

OPTIONS_DEFINE=		MANPAGES
MANPAGES_DESC=		Build and install manpages (requires textproc/docbook-xsl)

.include <bsd.port.options.mk>

.if defined(NO_PYTHON)
CONFIGURE_ARGS+=	--disable-python
.else
USES+=			python:2.7
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/ntdb.so
.endif

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ENV+=		XSLTPROC="true"
.else
BUILD_DEPENDS+=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
.endif

PLIST_FILES+=		bin/ntdbbackup \
			bin/ntdbdump \
			bin/ntdbrestore \
			bin/ntdbtool \
			include/ntdb.h \
			lib/libntdb.so \
			lib/libntdb.so.1 \
			%%PKGCONFIGDIR%%/ntdb.pc

# No fancy color error messages
.if ${COMPILER_TYPE} == "clang"
CFLAGS+=		-fno-color-diagnostics
.endif
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

TDB_MAN3=		man/man3/ntdb.3.gz

TDB_MAN8=		man/man8/ntdbbackup.8.gz \
			man/man8/ntdbdump.8.gz \
			man/man8/ntdbrestore.8.gz \
			man/man8/ntdbtool.8.gz

PLIST_FILES+=		${TDB_MAN3} ${TDB_MAN8}

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

pre-build:
.if ! ${PORT_OPTIONS:MMANPAGES}
			-${MKDIR} ${BUILD_WRKSRC}/bin/default/man
.	for man in ${TDB_MAN3} ${TDB_MAN8}
			${INSTALL_MAN} ${FILESDIR}/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.	endfor
.endif

.include <bsd.port.post.mk>
