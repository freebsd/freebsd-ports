# New ports collection makefile for:	talloc
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		talloc
PORTVERSION=		2.0.7
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.samba.org/pub/%SUBDIR%/ \
			ftp://ca.samba.org/pub/%SUBDIR%/ \
			ftp://de.samba.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Hierarchical pool based memory allocator

CONFLICTS=		samba33-3.*

USE_PYTHON_BUILD=	yes
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_SCRIPT=	${WAF_TOOL} configure
CONFIGURE_LOG=		bin/config.log
USE_GNOME=		pkgconfig

LICENSE=		LGPL3
MAKE_JOBS_SAFE=		yes

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

OPTIONS=		PYTHON		"Python bindings"	on

.include <bsd.port.options.mk>

MAN3=			talloc.3

PLIST_FILES=		include/talloc.h \
			lib/libtalloc.so \
			lib/libtalloc.so.2 \
			%%PKGCONFIGDIR%%/talloc.pc

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man

.if !defined(DISABLE_MAKE_JOBS)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS=		--jobs=${MAKE_JOBS_NUMBER}
.endif

.if defined(WITH_PYTHON)
USE_PYTHON_RUN=		yes
PLIST_FILES+=		include/pytalloc.h \
			lib/libpytalloc-util.so \
			lib/libpytalloc-util.so.2 \
			%%PYTHON_SITELIBDIR%%/talloc.so \
			%%PKGCONFIGDIR%%/pytalloc-util.pc
PLIST_DIRSTRY+=		%%PYTHON_SITELIBDIR%% \
			%%PYTHON_LIBDIR%%
.else
CONFIGURE_ARGS+=	--disable-python
.endif

ALL_TARGET=		build
INSTALL_TARGET=		install

post-patch:
			@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
				${BUILD_WRKSRC}/wscript

pre-build:
.for man in ${MAN3}
			@${MKDIR} ${BUILD_WRKSRC}/bin/default
			@${INSTALL_MAN} ${FILESDIR}/${man} ${BUILD_WRKSRC}/bin/default
.endfor

do-build:
			@(cd ${BUILD_WRKSRC}; \
			if ! ${SETENV} ${MAKE_ENV} ${BUILD_WRKSRC}/${WAF_TOOL} ${_MAKE_JOBS} ${MAKE_ARGS} build; then \
				if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
					${ECHO_MSG} "===> Compilation failed unexpectedly."; \
					(${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
				fi; \
			${FALSE}; \
			fi)

do-install:
			@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_WRKSRC}/${WAF_TOOL} ${MAKE_ARGS} install)

.include <bsd.port.mk>
