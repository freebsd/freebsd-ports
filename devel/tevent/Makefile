# New ports collection makefile for:	tevent
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tevent
PORTVERSION=		0.9.13
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.samba.org/pub/%SUBDIR%/ \
			ftp://ca.samba.org/pub/%SUBDIR%/ \
			ftp://de.samba.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Talloc based event loop library

CONFLICTS=

USE_PYTHON_BUILD=	yes
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_SCRIPT=	${WAF_TOOL} configure
USE_GNOME=		pkgconfig

LICENSE=		GPLv3
MAKE_JOBS_SAFE=		yes

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

OPTIONS=		PYTHON		"Python bindings"	on

.include <bsd.port.options.mk>

PLIST_FILES=		include/tevent.h \
			lib/libtevent.so \
			lib/libtevent.so.0 \
			%%PKGCONFIGDIR%%/tevent.pc

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man

LIB_DEPENDS+=		talloc.2:${PORTSDIR}/devel/talloc
CONFIGURE_ARGS+=	--bundled-libraries=!talloc

.if !defined(DISABLE_MAKE_JOBS)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS=		--jobs=${MAKE_JOBS_NUMBER}
.endif

.if defined(WITH_PYTHON)
USE_PYTHON_RUN=		yes
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/_tevent.so
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
