# New ports collection makefile for:	semi-1.13.x for emacs
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	semi
PORTVERSION=	${SEMI_VER}
PORTREVISION?=	1
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.13-for-flim-1.13/ \
		ftp://ftp.etl.go.jp/pub/mule/semi/semi-1.13-for-flim-1.13/ \
		ftp://ftp.media.kyoto-u.ac.jp/pub/mule/semi/semi-1.13-for-flim-1.13/ \
		ftp://ftp.win.or.jp/pub/word/mule/semi/semi-1.13-for-flim-1.13/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/emacs/mule/semi/semi-1.13-for-flim-1.13/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	SEMI, Library of MIME feature for GNU Emacs for emacs21

PORTCLASS?=	master

NO_LATEST_LINK=	yes

# distfile version
FLIM_TRUNK=	1.13
SEMI_TRUNK=	1.13
SEMI_VER=	1.13.7
# setupel filename
SEMI_SETUPEL=	semi-setupel.el
# document install directory by install-doc target
SEMIDOCDIR?=	share/doc/semi
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages
SEMI_COOKIE=	semi-${EMACS_PORT_NAME}-${SEMI_TRUNK}.FreeBSD-packages
# semi lispdir
SEMI_LISPDIR?=			${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
SEMI_VERSION_SPECIFIC_LISPDIR?=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs21
DEPPORT_SUFFIX=		
.else
DEPPORT_SUFFIX=		-${EMACS_PORT_NAME}
.endif

EMACS_MASTERDIR_PKGFILES=YES

# target name for make build
ALL_TARGET?=	elc
# environments
SCRIPTS_ENV+=	TARGETS="${SEMI_SETUPEL}"
PLIST_SUB+=	SEMIDOCDIR=${SEMIDOCDIR} SEMI_SETUPEL=${SEMI_SETUPEL} \
		SEMI_COOKIE=${SEMI_COOKIE}
MAKE_ARGS+=	PREFIX="${LOCALBASE}" \
		LISPDIR="${SEMI_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${SEMI_VERSION_SPECIFIC_LISPDIR}"

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
# depends on flim
BUILD_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${FLIM_TRUNK:S/.//}${DEPPORT_SUFFIX}
RUN_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${FLIM_TRUNK:S/.//}${DEPPORT_SUFFIX}
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
.if defined(EMACS_NO_SUBDIRSEL) && (${EMACS_NO_SUBDIRSEL} == "YES")
	@${CP} ${FILESDIR}/${SEMI_SETUPEL}.in ${WRKDIR}
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
	@${MKDIR} -p ${LOCALBASE}/share/semi
	@${TOUCH} ${LOCALBASE}/share/semi/${SEMI_COOKIE}
.if defined(EMACS_NO_SUBDIRSEL) && (${EMACS_NO_SUBDIRSEL} == "YES")
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

setupel-install:
	@${INSTALL_DATA} ${WRKDIR}/${SEMI_SETUPEL} \
		${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp

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
	${MKDIR} -p ${LOCALBASE}/${EMACS_PACKAGESDIR}/man/semi ; \
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
