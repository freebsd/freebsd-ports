# New ports collection makefile for:	flim-1.14.x for emacs21
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flim
PORTVERSION=	${FLIM_VER}
PORTEPOCH=	1
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/lemi/dist/flim/flim-1.14/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	FLIM, message representation or encoding elisp library for emacs

PORTCLASS?=	master

# distfile version
FLIM_VER=	${FLIM_TRUNK}.9
FLIM_TRUNK=	1.14
# document install directory by install-doc target
FLIMDOCDIR?=	share/doc/flim
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages
# flim lispdir
FLIM_LISPDIR=			${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
FLIM_VERSION_SPECIFIC_LISPDIR=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

PORTCLASS?=	master
USE_EMACS=	yes

EMACS_MASTERDIR_PKGFILES=YES
DESCR=		${PKGDIR}/pkg-descr

# target name for make build
ALL_TARGET?=	elc
# environments
PLIST_SUB+=	FLIMDOCDIR=${FLIMDOCDIR} FLIM_COOKIE=${FLIM_COOKIE}
MAKE_ARGS+=	PREFIX="${LOCALBASE}" \
		LISPDIR="${FLIM_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${FLIM_VERSION_SPECIFIC_LISPDIR}"

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
.if (${EMACS_PORT_NAME} == "emacs22") || (${EMACS_PORT_NAME} == "emacs-devel")
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif
.if (${EMACS_PORT_NAME} == "emacs21") || (${EMACS_PORT_NAME} == "emacs22") || (${EMACS_PORT_NAME} == "emacs-devel")
PLIST=		${PKGDIR}/pkg-plist.emacs21
.endif
# depends on apel (case of xemacs-21.x or later)
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/apel/emu.el:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/apel/emu.el:${PORTSDIR}/editors/xemacs-packages
.else
# depends on apel (case of gnu emacsen etc...)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}
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

# makeinfo stuff
MAKEINFO=		makeinfo --no-split --no-validate
MAKEINFO_EMACS=		${EMACS_CMD} -no-site-file -no-init-file -batch
MAKEINFO_EMACS_FLAGS=	-e texinfo-format-buffer -f save-buffer

.if defined(EMACS_PACKAGESDIR) && defined(XEMACS_PKGNAME)
pre-build: pkg-el-copy
.endif

.if defined(BUILD_INFO_BY_EMACS) && (${BUILD_INFO_BY_EMACS} == "YES")
post-build: info-build-by-emacs
.else
post-build: info-build
.endif

.if defined(EMACS_PACKAGESDIR) && defined(EMACS_PACKAGES_SUBDIRS)
pre-install: mkdir-site-packages
.endif
.if defined(EMACS_PACKAGESDIR) && defined(XEMACS_PKGNAME)
pre-install: pkg-el-install
.endif

POST_INSTALL_TARGET=	pkgcookie-install
.if defined(EMACS_PACKAGESDIR) && defined(MANIFEST)
POST_INSTALL_TARGET+=	info-package-install manifest-install
.else
POST_INSTALL_TARGET+=	info-install
.endif
.if !defined(NOPORTDOCS)
POST_INSTALL_TARGET+=	doc-install
.endif

post-install: ${POST_INSTALL_TARGET}

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
	${MKDIR} ${LOCALBASE}/${EMACS_PACKAGESDIR}/man/flim ; \
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

pkgcookie-install:
# install package-cookie
	@${MKDIR} ${LOCALBASE}/share/flim
	@${TOUCH} ${LOCALBASE}/share/flim/${FLIM_COOKIE}

.include <bsd.port.post.mk>
