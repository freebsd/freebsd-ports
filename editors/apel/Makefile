# New ports collection makefile for:	apel for emacs
# Version required:	9.12
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=	apel-${APEL_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/apel/

MAINTAINER?=	shige@kuis.kyoto-u.ac.jp

# distfile version
APEL_VER=	9.12
APEL_SETUPEL=	apel-setup.el

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}
REQUIRE_SETUPEL=  YES
.endif

# target name for make build
ALL_TARGET?=	elc

.if defined(EMACS_PORT)
PKGNAME=	apel-${EMACS_PORT}-${APEL_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	NO
.endif
.if !defined(REQUIRE_SETUPEL)
REQUIRE_SETUPEL=	NO
.endif
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
MAKE_FLAGS=	EMACS=${EMACS_CMD}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR."
	@${FALSE}
.endif

.if (${REQUIRE_SETUPEL} == "YES")
pre-configure:
	@${CP} ${FILESDIR}/${APEL_SETUPEL}.in ${WRKDIR}

post-install:
	@${INSTALL_DATA} ${WRKDIR}/${APEL_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif

.include <bsd.port.mk>
