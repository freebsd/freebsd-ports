# New ports collection makefile for:	flim-current for emacs
# Version required:	1.13.2
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	flim-${FLIM_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/flim/flim-1.13/ \
		ftp://ftp.media.kyoto-u.ac.jp/pub/mule/flim/flim-1.13/ \
		ftp://ftp.win.or.jp/pub/word/mule/flim/flim-1.13/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/emacs/mule/flim/flim-1.13/
MAINTAINER?=	shige@FreeBSD.org

PORTCLASS?=	master

# distfile version
FLIM_VER=	1.13.2
# setupel filename
FLIM_SETUPEL=	flim-setupel.el
# document install directory by install-doc target
FLIMDOCDIR?=	share/doc/flim
FLIM_COOKIE=	flim-${EMACS_PORT}-${FLIM_VER}.FreeBSD-packages

.if (${PORTCLASS} == "master")
# for emacs
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}
# whether emacs requires *-setupel.el
REQUIRE_SETUPEL= YES
.endif

# target name for make build
ALL_TARGET?=	elc

.if defined(EMACS_PORT)
PKGNAME=	flim-${EMACS_PORT}-${FLIM_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAS_COMMON_PORT) && (${HAS_COMMON_PORT} == "YES")
RUN_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		TARGETS="${FLIM_SETUPEL}"
PLIST_SUB+=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		FLIMDOCDIR=${FLIMDOCDIR} FLIM_SETUPEL=${FLIM_SETUPEL} \
		FLIM_COOKIE=${FLIM_COOKIE}
MAKE_FLAGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD}
.if (${EMACS_VER} == "19.34")
# depends on custom: emacs-19.34 or mule-19.34
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
.endif
# depends on apel (case of xemacs-21.x or later)
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
.else
# depends on apel (case of other emacsen etc...)
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
.endif
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
	@${CP} ${FILESDIR}/${FLIM_SETUPEL}.in ${WRKDIR}
.endif

.include <bsd.port.pre.mk>

# makeinfo stuff
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
# install package-cookie
	@${MKDIR} -p ${PREFIX}/share/flim
	@${TOUCH} ${PREFIX}/share/flim/${FLIM_COOKIE}
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
	for i in mime-en.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)
.if defined(HAS_MULE) && (${HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ja.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)
.endif

info-build-by-emacs:
	@(cd ${WRKSRC} ; \
	for i in mime-en.texi; do \
		${MAKEINFO_EMACS} $${i} ${MAKEINFO_EMACS_FLAGS} || ${TRUE} ; \
	done)
.if defined(HAS_MULE) && (${HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ja.texi; do \
		${MAKEINFO_EMACS} $${i} ${MAKEINFO_EMACS_FLAGS} || ${TRUE} ; \
	done)
.endif

mkdir-site-packages:
	@(for i in ${EMACS_PACKAGES_SUBDIRS} ; do \
		${MKDIR} ${PREFIX}/${EMACS_PACKAGESDIR}/$${i} ; \
	done)

doc-install:
	@${MKDIR} ${PREFIX}/${FLIMDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* VERSION ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${FLIMDOCDIR}/ ; \
	done)

setupel-install:
	@${INSTALL_DATA} ${WRKDIR}/${FLIM_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp


info-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.if defined(HAS_MULE) && (${HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.endif

info-package-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
				${PREFIX}/${EMACS_PACKAGESDIR}/info ; \
	done ; \
	${MKDIR} -p ${PREFIX}/${EMACS_PACKAGESDIR}/man/flim ; \
	for i in mime-en.texi mime-ja.texi; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
				${PREFIX}/${EMACS_PACKAGESDIR}/man/flim ; \
	done)

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PKGDIR}/PLIST | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
