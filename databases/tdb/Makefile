# $FreeBSD$

PORTNAME=		tdb
PORTVERSION=		1.2.12
PORTREVISION=		0
PORTEPOCH=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Trivial Database

LICENSE=		GPLv3

CONFLICTS=		*samba3[0-4]-3.*

USE_PYTHON_BUILD=	2
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_SCRIPT=	${WAF_TOOL} configure
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

MAN8=			tdbbackup.8 \
			tdbdump.8 \
			tdbrestore.8 \
			tdbtool.8

PLIST_FILES=		bin/tdbbackup \
			bin/tdbdump \
			bin/tdbrestore \
			bin/tdbtool \
			include/tdb.h \
			lib/libtdb.so \
			lib/libtdb.so.1 \
			%%PKGCONFIGDIR%%/tdb.pc

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

.if !defined(DISABLE_MAKE_JOBS) && !defined(MAKE_JOBS_UNSAFE)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS=		--jobs=${MAKE_JOBS_NUMBER}
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON_RUN=		yes
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/tdb.so
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

pre-build:
.for man in ${MAN8}
			@${MKDIR} ${BUILD_WRKSRC}/bin/default/man
			@${INSTALL_MAN} ${FILESDIR}/${man} ${BUILD_WRKSRC}/bin/default/man
.endfor

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
