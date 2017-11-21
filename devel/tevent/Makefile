# $FreeBSD$

PORTNAME=		tevent
PORTVERSION=		0.9.34
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel
MASTER_SITES=		SAMBA

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Talloc based event loop library

LICENSE=		LGPL3

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

BUILD_DEPENDS=		talloc>=2.1.10:devel/talloc
RUN_DEPENDS=		talloc>=2.1.10:devel/talloc

USES=			compiler pkgconfig waf
USE_LDCONFIG=		yes
WAF_CMD=		buildtools/bin/waf
CONFIGURE_LOG=		bin/config.log

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--bundled-libraries=!talloc

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
			--infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR} \
			--disable-rpath \
			--without-gettext

OPTIONS_DEFINE=		MANPAGES
MANPAGES_DESC=		Build and install manpages (requires textproc/docbook-xsl)

.include <bsd.port.options.mk>

PLIST_FILES+=		include/tevent.h \
			lib/libtevent.so \
			lib/libtevent.so.0 \
			%%PKGCONFIGDIR%%/tevent.pc

.if defined(NO_PYTHON)
USES+=			python:2.7,build
CONFIGURE_ARGS+=	--disable-python
.else
USES+=			python:2.7

PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/_tevent.so \
			%%PYTHON_SITELIBDIR%%/tevent.py  \
			%%PYTHON_SITELIBDIR%%/tevent.pyc \
			%%PYTHON_SITELIBDIR%%/tevent.pyo
# XXX: This is a gross hack to make port use both Python 2.7+ and 3.3+
# This is not officially supported, use at your own risk
.if defined(WITH_SAMBA_PYTHON3) && ${WITH_SAMBA_PYTHON3:Mpython3\.[0-9]}
SAMBA_PYTHON3=		${WITH_SAMBA_PYTHON3}
SAMBA_PYTHON3_VERSION:=	${SAMBA_PYTHON3:S/^python//}
SAMBA_PYTHON3_VER:=	${SAMBA_PYTHON3_VERSION:C/\.//}
.if !exists(${PORTSDIR}/lang/python${SAMBA_PYTHON3_VER})
.error			unsupported or unknown Python version ${SAMBA_PYTHON3_VERSION}
.endif
BUILD_DEPENDS+=		${SAMBA_PYTHON3}:lang/python${SAMBA_PYTHON3_VER}
RUN_DEPENDS+=		${SAMBA_PYTHON3}:lang/python${SAMBA_PYTHON3_VER}
# cpython-36m
SAMBA_PYTHON3_SO_ABI!=	[ ! -f "${LOCALBASE}/bin/${SAMBA_PYTHON3}" ] || ${LOCALBASE}/bin/${SAMBA_PYTHON3} -c 'import sysconfig; print(sysconfig.get_config_var("SOABI") or "")' 2>/dev/null
SAMBA_PYTHON3_SITELIBDIR=lib/python${SAMBA_PYTHON3_VERSION}/site-packages

CONFIGURE_ENV+=		PYTHON3_SO_ABI_FLAG=.${SAMBA_PYTHON3_SO_ABI}
CONFIGURE_ARGS+=	--extra-python=${LOCALBASE}/bin/${SAMBA_PYTHON3}

PLIST_SUB+=		SAMBA_PYTHON3_SO_ABI=${SAMBA_PYTHON3_SO_ABI} \
			SAMBA_PYTHON3_SITELIBDIR=${SAMBA_PYTHON3_SITELIBDIR}

PLIST_FILES+=		%%SAMBA_PYTHON3_SITELIBDIR%%/_tevent.so \
			%%SAMBA_PYTHON3_SITELIBDIR%%/tevent.py  \
			%%SAMBA_PYTHON3_SITELIBDIR%%/tevent.pyc \
			%%SAMBA_PYTHON3_SITELIBDIR%%/tevent.pyo
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

post-build:
			${PYTHON_CMD} -m py_compile ${BUILD_WRKSRC}/tevent.py
			${PYTHON_CMD} -O -m py_compile ${BUILD_WRKSRC}/tevent.py

post-install:
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtevent.so
.if !defined(NO_PYTHON)
			${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_tevent.so
.if defined(SAMBA_PYTHON3)
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SAMBA_PYTHON3_SITELIBDIR}/_tevent.so
.endif
.endif

.include <bsd.port.post.mk>
