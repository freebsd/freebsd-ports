# $FreeBSD$

PORTNAME=		tdb
PORTVERSION=		1.3.15
PORTREVISION=		1
PORTEPOCH=		1
CATEGORIES=		databases
MASTER_SITES=		SAMBA

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Trivial Database

LICENSE=		GPLv3

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

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

TDB_BINS=		bin/tdbbackup \
			bin/tdbdump \
			bin/tdbrestore \
			bin/tdbtool

PLIST_FILES+=		include/tdb.h \
			${TDB_BINS} \
			lib/libtdb.so \
			lib/libtdb.so.1 \
			%%PKGCONFIGDIR%%/tdb.pc

.if defined(NO_PYTHON)
USES+=			python:2.7,build
CONFIGURE_ARGS+=	--disable-python
.else
USES+=			python:2.7

PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/tdb.so \
			%%PYTHON_SITELIBDIR%%/_tdb_text.py
# XXX: This is a gross hack to make port use both Python 2.7+ and 3.3+
# This is not officially supported, use at your own risk
.if defined(WITH_SAMBA4_PYTHON3) && ${WITH_SAMBA4_PYTHON3:Mpython3\.[0-9]}
SAMBA4_PYTHON3=		${WITH_SAMBA4_PYTHON3}
SAMBA4_PYTHON3_VERSION:=${SAMBA4_PYTHON3:S/^python//}
SAMBA4_PYTHON3_VER:=	${SAMBA4_PYTHON3_VERSION:C/\.//}
.if !exists(${PORTSDIR}/lang/python${SAMBA4_PYTHON3_VER})
.error			unsupported or unknown Python version ${SAMBA4_PYTHON3_VERSION}
.endif
BUILD_DEPENDS+=		${SAMBA4_PYTHON3}:lang/python${SAMBA4_PYTHON3_VER}
RUN_DEPENDS+=		${SAMBA4_PYTHON3}:lang/python${SAMBA4_PYTHON3_VER}
# cpython-36m
SAMBA4_PYTHON3_SO_ABI!=	[ ! -f "${LOCALBASE}/bin/${SAMBA4_PYTHON3}" ] || ${LOCALBASE}/bin/${SAMBA4_PYTHON3} -c 'import sysconfig; print(sysconfig.get_config_var("SOABI") or "")' 2>/dev/null
SAMBA4_PYTHON3_SITELIBDIR=lib/python${SAMBA4_PYTHON3_VERSION}/site-packages

CONFIGURE_ENV+=		PYTHON3_SO_ABI_FLAG=.${SAMBA4_PYTHON3_SO_ABI}
CONFIGURE_ARGS+=	--extra-python=${LOCALBASE}/bin/${SAMBA4_PYTHON3}

PLIST_SUB+=		SAMBA4_PYTHON3_SO_ABI=${SAMBA4_PYTHON3_SO_ABI} \
			SAMBA4_PYTHON3_SITELIBDIR=${SAMBA4_PYTHON3_SITELIBDIR}

PLIST_FILES+=		%%SAMBA4_PYTHON3_SITELIBDIR%%/tdb.so \
			%%SAMBA4_PYTHON3_SITELIBDIR%%/_tdb_text.py
.endif
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
.if defined(SAMBA4_PYTHON3)
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SAMBA4_PYTHON3_SITELIBDIR}/tdb.so
.endif
.endif

.include <bsd.port.post.mk>
