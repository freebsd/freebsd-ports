# New ports collection makefile for:	flim-current for emacs
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flim
PORTVERSION=	${FLIM_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/flim/flim-1.13/ \
		ftp://ftp.media.kyoto-u.ac.jp/pub/mule/flim/flim-1.13/ \
		ftp://ftp.win.or.jp/pub/word/mule/flim/flim-1.13/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/emacs/mule/flim/flim-1.13/
MAINTAINER?=	shige@FreeBSD.org
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

PORTCLASS?=	master

# distfile version
FLIM_VER=	1.13.2
# setupel filename
FLIM_SETUPEL=	flim-setupel.el
# document install directory by install-doc target
FLIMDOCDIR?=	share/doc/flim
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_VER}.FreeBSD-packages

.if (${PORTCLASS} == "master")
# for emacs
EMACS_PORT_NAME=	emacs
# whether emacs requires *-setupel.el
REQUIRE_SETUPEL= YES
.endif

# target name for make build
ALL_TARGET?=	elc
# environments
SCRIPTS_ENV+=	TARGETS="${FLIM_SETUPEL}"
PLIST_SUB+=	FLIMDOCDIR=${FLIMDOCDIR} FLIM_SETUPEL=${FLIM_SETUPEL} \
		FLIM_COOKIE=${FLIM_COOKIE}

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
# depends on apel (case of xemacs-21.x or later)
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.elif (${EMACS_PORT_NAME} == "xemacs") || (${EMACS_PORT_NAME} == "xemacs20")
# depends on apel (case of xemacs-20.x or former)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.else
# depends on apel (case of other emacsen etc...)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.endif
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
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

# makeinfo stuff
MAKEINFO=		makeinfo --no-split --no-validate
MAKEINFO_EMACS=		${EMACS_CMD} -no-site-file -no-init-file -batch
MAKEINFO_EMACS_FLAGS=	-e texinfo-format-buffer -f save-buffer

pre-build:
.if defined(EMACS_PACKAGESDIR) && defined(XEMACS_PKGNAME)
	@${MAKE} pkg-el-copy
.endif

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
.if defined(EMACS_PACKAGESDIR) && defined(XEMACS_PKGNAME)
	@${MAKE} pkg-el-install
.endif

post-install:
# install package-cookie
	@${MKDIR} -p ${LOCALBASE}/share/flim
	@${TOUCH} ${LOCALBASE}/share/flim/${FLIM_COOKIE}
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
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
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
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ja.texi; do \
		${MAKEINFO_EMACS} $${i} ${MAKEINFO_EMACS_FLAGS} || ${TRUE} ; \
	done)
.endif

pkg-el-copy:
	@(if [ -f ${FILESDIR}/_pkg.el ] ; then \
	${CP} ${FILESDIR}/_pkg.el ${WRKSRC}/_pkg.el ;\
	fi)

pkg-el-install:
	@(if [ -f ${FILESDIR}/_pkg.el ] ; then \
	${MKDIR} ${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME} ;\
	${INSTALL_DATA} ${FILESDIR}/_pkg.el \
		${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME}/_pkg.el ;\
	fi)

mkdir-site-packages:
	@(for i in ${EMACS_PACKAGES_SUBDIRS} ; do \
		${MKDIR} ${LOCALBASE}/${EMACS_PACKAGESDIR}/$${i} ; \
	done)

doc-install:
	@${MKDIR} ${LOCALBASE}/${FLIMDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* VERSION ; do \
		${INSTALL_DATA} $${i} ${LOCALBASE}/${FLIMDOCDIR}/ ; \
	done)

setupel-install:
	@${INSTALL_DATA} ${WRKDIR}/${FLIM_SETUPEL} \
			${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp


info-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/info ; \
		install-info ${LOCALBASE}/info/$${i} ${LOCALBASE}/info/dir ; \
	done)
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/info ; \
		install-info ${LOCALBASE}/info/$${i} ${LOCALBASE}/info/dir ; \
	done)
.endif

info-package-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
				${LOCALBASE}/${EMACS_PACKAGESDIR}/info ; \
	done ; \
	${MKDIR} -p ${LOCALBASE}/${EMACS_PACKAGESDIR}/man/flim ; \
	for i in mime-en.texi mime-ja.texi; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
				${LOCALBASE}/${EMACS_PACKAGESDIR}/man/flim ; \
	done)

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PLIST} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${LOCALBASE}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
