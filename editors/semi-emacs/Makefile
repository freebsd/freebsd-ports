# New ports collection makefile for:	semi for emacs
# Version required:	1.8.6
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	semi-${SEMI_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/semi/semi-1.08-for-flim-1.9/

MAINTAINER?=	shige@FreeBSD.org

PORTCLASS?=	master

# distfile version
FLIM_VER=	1.9.2
SEMI_VER=	1.8.6
SEMIDOCDIR=	share/doc/semi
SEMI_SETUPEL=	semi-setupel.el

.if (${PORTCLASS} == "master")
# emacs port setup
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}
REQUIRE_SETUPEL=  YES
.endif

# target name for make build
ALL_TARGET?=	elc

# if RUN_DEPENDS-emacs port name has the suffix '-common'.
.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	NO
.endif
# if RUN_DEPENDS-emacs needs setup elisp
.if !defined(REQUIRE_SETUPEL)
REQUIRE_SETUPEL=	NO
.endif

.if defined(EMACS_PORT)
PKGNAME=	semi-${EMACS_PORT}-${SEMI_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		TARGETS="${SEMI_SETUPEL}"
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		SEMIDOCDIR=${SEMIDOCDIR} SEMI_SETUPEL=${SEMI_SETUPEL}
MAKE_FLAGS=	EMACS=${EMACS_CMD}
.if (${EMACS_VER} == "19.34")
# depends on custom: emacs-19.34 or mule-19.34
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
.endif
# depends on apel
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
# depends on flim
BUILD_DEPENDS+=	${PKG_DBDIR}/flim-${EMACS_PORT}-${FLIM_VER}:${PORTSDIR}/editors/flim-${EMACS_PORT}
RUN_DEPENDS+=	${PKG_DBDIR}/flim-${EMACS_PORT}-${FLIM_VER}:${PORTSDIR}/editors/flim-${EMACS_PORT}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR, EMACS_LIBDIR_WITH_VER."
	@${FALSE}
.endif

# info files JIS to EUC
BUILD_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf

.if (${REQUIRE_SETUPEL} == "YES")
pre-configure:
	@${CP} ${FILESDIR}/${SEMI_SETUPEL}.in ${WRKDIR}
.endif

.include <bsd.port.pre.mk>

MAKEINFO=	makeinfo --no-split --no-validate

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${ECHO_MSG} "===>   Please ignore the following errors." ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.if (${REQUIRE_SETUPEL} == "YES")
	@${INSTALL_DATA} ${WRKDIR}/${SEMI_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${SEMIDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${SEMIDOCDIR}/ ; \
	done)
.endif

.include <bsd.port.post.mk>
