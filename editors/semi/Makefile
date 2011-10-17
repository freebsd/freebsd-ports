# New ports collection makefile for:	semi-current for emacs
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	semi
PORTVERSION=	${SEMI_VER}
PORTREVISION=	10
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/comp/emacsen/lisp/semi/semi-1.14-for-flim-1.14/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	SEMI, Library of MIME feature for GNU Emacs for emacs

PORTCLASS?=	master

# distfile version
FLIM_TRUNK=	1.14
SEMI_TRUNK=	1.14
SEMI_VER=	${SEMI_TRUNK}.6
# document install directory by install-doc target
SEMIDOCDIR?=	share/doc/semi
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages
SEMI_COOKIE=	semi-${EMACS_PORT_NAME}-${SEMI_TRUNK}.FreeBSD-packages
# semi lispdir
SEMI_LISPDIR=			${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
SEMI_VERSION_SPECIFIC_LISPDIR=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

USE_EMACS=	yes

EMACS_MASTERDIR_PKGFILES=YES
DESCR=		${PKGDIR}/pkg-descr

# target name for make build
ALL_TARGET?=	elc
# environments
PLIST_SUB+=	SEMIDOCDIR=${SEMIDOCDIR} SEMI_COOKIE=${SEMI_COOKIE}
MAKE_ARGS+=	PREFIX="${LOCALBASE}" \
		LISPDIR="${SEMI_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${SEMI_VERSION_SPECIFIC_LISPDIR}"

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
.if (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs-devel")
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif
.if (${EMACS_PORT_NAME} == "emacs20") || (${EMACS_PORT_NAME} == "emacs21") || (${EMACS_PORT_NAME} == "emacs22") || (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs-devel")
PLIST=		${PKGDIR}/pkg-plist.emacs20
.endif
# depends on flim
BUILD_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${DEPPORT_SUFFIX}
RUN_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${DEPPORT_SUFFIX}
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
	@${MKDIR} ${LOCALBASE}/share/semi
	@${TOUCH} ${LOCALBASE}/share/semi/${SEMI_COOKIE}
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
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
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
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ui-ja.texi; do \
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
	@${MKDIR} ${LOCALBASE}/${SEMIDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} $${i} ${LOCALBASE}/${SEMIDOCDIR}/ ; \
	done)

info-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/info ; \
		install-info ${LOCALBASE}/info/$${i} ${LOCALBASE}/info/dir ; \
	done)
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/info ; \
		install-info ${LOCALBASE}/info/$${i} ${LOCALBASE}/info/dir ; \
	done)
.endif

info-package-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${LOCALBASE}/${EMACS_PACKAGESDIR}/info ; \
	done ; \
	${MKDIR} ${LOCALBASE}/${EMACS_PACKAGESDIR}/man/semi ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${LOCALBASE}/${EMACS_PACKAGESDIR}/man/semi ; \
	done)

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PLIST} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${LOCALBASE}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
