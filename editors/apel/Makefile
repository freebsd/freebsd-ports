# New ports collection makefile for:	apel for emacs
# Version required:	9.20
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	apel-${APEL_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/apel/ \
		ftp://ftp.center.osaka-u.ac.jp/mule/apel/

MAINTAINER?=	shige@FreeBSD.org

# distfile version
APEL_VER=	9.20
APEL_SETUPEL=	apel-setupel.el
APELDOCDIR=	share/doc/apel

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}
# emacs requires *-setupel.el
REQUIRE_SETUPEL=  YES
.endif

# target name for make build
ALL_TARGET?=	elc

# if RUN_DEPENDS emacs port name has the suffix `-common'
.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	NO
.endif
# if RUN_DEPENDS emacs needs setup elisp
.if !defined(REQUIRE_SETUPEL)
REQUIRE_SETUPEL=	NO
.endif

.if defined(EMACS_PORT)
PKGNAME=	apel-${EMACS_PORT}-${APEL_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		TARGETS="${APEL_SETUPEL}"
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		APELDOCDIR=${APELDOCDIR} APEL_SETUPEL=${APEL_SETUPEL}
MAKE_FLAGS+=	EMACS=${EMACS_CMD}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR, EMACS_LIBDIR_WITH_VER."
	@${FALSE}
.endif

.if (${REQUIRE_SETUPEL} == "YES")
pre-configure:
	@${CP} ${FILESDIR}/${APEL_SETUPEL}.in ${WRKDIR}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${APELDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${APELDOCDIR}/ ; \
	done)
.endif
.if (${REQUIRE_SETUPEL} == "YES")
	@${INSTALL_DATA} ${WRKDIR}/${APEL_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.endif

.include <bsd.port.mk>
