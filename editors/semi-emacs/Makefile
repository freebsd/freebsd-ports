# New ports collection makefile for:	semi for emacs
# Version required:	1.13.4
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	semi-${SEMI_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/semi/semi-1.13-for-flim-1.12/ \
		ftp://ftp.media.kyoto-u.ac.jp/pub/mule/semi/semi-1.13-for-flim-1.12/ \
		ftp://ftp.win.or.jp/pub/word/mule/semi/semi-1.13-for-flim-1.12/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/emacs/mule/semi/semi-1.13-for-flim-1.12/

MAINTAINER?=	shige@FreeBSD.org

PORTCLASS?=	master

# distfile version
FLIM_VER=	1.12.7
SEMI_VER=	1.13.4
# setupel filename
SEMI_SETUPEL=	semi-setupel.el
# document install directory by install-doc target
SEMIDOCDIR?=	share/doc/semi
FLIM_COOKIE=	flim-${EMACS_PORT}-${FLIM_VER}.FreeBSD-packages
SEMI_COOKIE=	semi-${EMACS_PORT}-${SEMI_VER}.FreeBSD-packages

.if (${PORTCLASS} == "master")
# emacs port setup
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}
# whether emacs requires *-setupel.el
REQUIRE_SETUPEL=  YES
.endif

# target name for make build
ALL_TARGET?=	elc

.if defined(EMACS_PORT)
PKGNAME=	semi-${EMACS_PORT}-${SEMI_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAS_COMMON_PORT) && (${HAS_COMMON_PORT} == "YES")
RUN_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		TARGETS="${SEMI_SETUPEL}"
PLIST_SUB+=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		SEMIDOCDIR=${SEMIDOCDIR} SEMI_SETUPEL=${SEMI_SETUPEL} \
		SEMI_COOKIE=${SEMI_COOKIE}
MAKE_FLAGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD}
.if (${EMACS_VER} == "19.34")
# depends on custom: emacs-19.34 or mule-19.34
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
.endif
# depends on apel (case of xemacs-21.x or later)
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+= ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=   ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
.else
# depends on apel (case of other emacsen etc...)
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
.endif
# depends on flim
BUILD_DEPENDS+=	${PREFIX}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim-${EMACS_PORT}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR, EMACS_LIBDIR_WITH_VER."
	@${FALSE}
.endif

.if !defined(BUILD_INFO_BY_EMACS) || (${BUILD_INFO_BY_EMACS} == "NO")
# info files JIS to EUC
BUILD_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf
.endif

pre-configure:
.if defined(REQUIRE_SETUPEL) && (${REQUIRE_SETUPEL} == "YES")
	@${CP} ${FILESDIR}/${SEMI_SETUPEL}.in ${WRKDIR}
.endif

.include <bsd.port.pre.mk>

MAKEINFO=		makeinfo --no-split --no-validate
MAKEINFO_EMACS=		${EMACS_CMD} -no-site-file -no-init-file -batch
MAKEINFO_EMACS_FLAGS=	-e texinfo-format-buffer -f save-buffer

post-build:
.if defined(BUILD_INFO_BY_EMACS) && (${BUILD_INFO_BY_EMACS} == "YES")
	@${MAKE} info-build-by-emacs
.else
	@${MAKE} info-build
.endif

pre-install:
.if defined(EMACS_PACKAGESDIR) && defined(EMACS_PACKAGES_SUBDIRS)
	@${MAKE} mkdir-site-packages
.endif

post-install:
	@${MKDIR} -p ${PREFIX}/share/semi
	@${TOUCH} ${PREFIX}/share/semi/${SEMI_COOKIE}
.if defined(REQUIRE_SETUPEL) && (${REQUIRE_SETUPEL} == "YES")
	@${MAKE} setupel-install
.endif
.if defined(EMACS_PACKAGESDIR) && defined(MANIFEST)
	@${MAKE} info-package-install
	@${MAKE} manifest-install
.else
	@${MAKE} info-install
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} doc-install
.endif


###############################################################################
#
# miscellaneous local functions
#
info-build:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)
.if defined(HAS_MULE) && (${HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ui-ja.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)
.endif

info-build-by-emacs:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.texi; do \
		${MAKEINFO_EMACS} $${i} ${MAKEINFO_EMACS_FLAGS} || ${TRUE} ; \
	done)
.if defined(HAS_MULE) && (${HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ui-ja.texi; do \
		${MAKEINFO_EMACS} $${i} ${MAKEINFO_EMACS_FLAGS} || ${TRUE} ; \
	done)
.endif

mkdir-site-packages:
	@(for i in ${EMACS_PACKAGES_SUBDIRS} ; do \
		${MKDIR} ${PREFIX}/${EMACS_PACKAGESDIR}/$${i} ; \
	done)

doc-install:
	@${MKDIR} ${PREFIX}/${SEMIDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${SEMIDOCDIR}/ ; \
	done)

setupel-install:
	@${INSTALL_DATA} ${WRKDIR}/${SEMI_SETUPEL} \
		${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp

info-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.if defined(HAS_MULE) && (${HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.endif

info-package-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${PREFIX}/${EMACS_PACKAGESDIR}/info ; \
	done ; \
	${MKDIR} -p ${PREFIX}/${EMACS_PACKAGESDIR}/man/semi ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${PREFIX}/${EMACS_PACKAGESDIR}/man/semi ; \
	done)

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PKGDIR}/PLIST | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
