# New ports collection makefile for:	tdb
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tdb
PORTVERSION=		1.2.9
PORTREVISION=		0
PORTEPOCH=		1
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.samba.org/pub/%SUBDIR%/ \
			ftp://ca.samba.org/pub/%SUBDIR%/ \
			ftp://de.samba.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Trivial Database

LICENSE=		GPLv3

CONFLICTS=		*samba3[0-4]-3.*

USE_PYTHON_BUILD=	-2.7
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_SCRIPT=	${WAF_TOOL} configure
USE_GNOME=		pkgconfig

MAKE_JOBS_SAFE=		yes

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

OPTIONS=		PYTHON		"Python bindings"	on

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

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man

.if !defined(DISABLE_MAKE_JOBS) && !defined(MAKE_JOBS_UNSAFE)
.if defined(MAKE_JOBS_SAFE) || defined(FORCE_MAKE_JOBS)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS=		--jobs=${MAKE_JOBS_NUMBER}
.endif
.endif

.if defined(WITH_PYTHON)
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
			@${MKDIR} ${BUILD_WRKSRC}/bin/default/manpages
			@${INSTALL_MAN} ${FILESDIR}/${man} ${BUILD_WRKSRC}/bin/default/manpages
.endfor

do-build:
			@(cd ${BUILD_WRKSRC}; \
			if ! ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${BUILD_WRKSRC}/${WAF_TOOL} ${_MAKE_JOBS} ${MAKE_ARGS} build; then \
				if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
					${ECHO_MSG} "===> Compilation failed unexpectedly."; \
					(${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
				fi; \
			${FALSE}; \
			fi)

do-install:
			@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_WRKSRC}/${WAF_TOOL} ${MAKE_ARGS} install)

.include <bsd.port.post.mk>
