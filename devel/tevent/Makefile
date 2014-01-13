# $FreeBSD$

PORTNAME=		tevent
PORTVERSION=		0.9.18
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Talloc based event loop library

LICENSE=		LGPL3

CONFLICTS=

USE_PYTHON_BUILD=	2
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_SCRIPT=	${WAF_TOOL} configure
CONFIGURE_LOG=		bin/config.log
USES=			pkgconfig


PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--mandir=${MANPREFIX}/man \
			--infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON

NO_STAGE=	yes
.include <bsd.port.options.mk>

PLIST_FILES=		include/tevent.h \
			lib/libtevent.so \
			lib/libtevent.so.0 \
			%%PKGCONFIGDIR%%/tevent.pc

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

BUILD_DEPENDS+=		talloc>=2.0.8:${PORTSDIR}/devel/talloc
RUN_DEPENDS:=		${BUILD_DEPENDS}

CONFIGURE_ARGS+=	--bundled-libraries=!talloc

.if !defined(DISABLE_MAKE_JOBS) && !defined(MAKE_JOBS_UNSAFE)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS=		--jobs=${MAKE_JOBS_NUMBER}
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON_RUN=		yes
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/_tevent.so \
			%%PYTHON_SITELIBDIR%%/tevent.py  \
			%%PYTHON_SITELIBDIR%%/tevent.pyc \
			%%PYTHON_SITELIBDIR%%/tevent.pyo
PLIST_DIRSTRY+=		%%PYTHON_SITELIBDIR%% \
			%%PYTHON_LIBDIR%%
.else
CONFIGURE_ARGS+=	--disable-python
.endif

ALL_TARGET=		build
INSTALL_TARGET=		install

.include <bsd.port.pre.mk>

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

post-patch:
			@${REINPLACE_CMD} -e 's|python|python${PYTHON_VER}|' ${BUILD_WRKSRC}/${WAF_TOOL}
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

do-build:
			@(cd ${BUILD_WRKSRC}; \
			if ! ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${BUILD_WRKSRC}/${WAF_TOOL} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
				if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
					${ECHO_MSG} "===> Compilation failed unexpectedly."; \
					(${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
				fi; \
			${FALSE}; \
			fi)

post-build:
.if ${PORT_OPTIONS:MPYTHON}
			${PYTHON_CMD} -m py_compile ${BUILD_WRKSRC}/tevent.py
			${PYTHON_CMD} -O -m py_compile ${BUILD_WRKSRC}/tevent.py
.endif

do-install:
			@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_WRKSRC}/${WAF_TOOL} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
