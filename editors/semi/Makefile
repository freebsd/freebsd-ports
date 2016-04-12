# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	semi
PORTVERSION=	${SEMI_VER}
PORTREVISION=	17
CATEGORIES=	editors elisp
MASTER_SITES=	http://git.chise.org/elisp/dist/semi/semi-1.14-for-flim-1.14/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	SEMI, Library of MIME feature for GNU Emacs for emacs

LICENSE=	GPLv2

USES=		makeinfo

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
MAKE_ARGS+=	PREFIX="${STAGEDIR}${LOCALBASE}" \
		LISPDIR="${STAGEDIR}${SEMI_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${SEMI_VERSION_SPECIFIC_LISPDIR}"

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if defined(EMACS_PORT_NAME)
.if (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs24") || (${EMACS_PORT_NAME} == "emacs-devel")
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif
.if (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs24") || (${EMACS_PORT_NAME} == "emacs-devel")
PLIST=		${PKGDIR}/pkg-plist.emacs20
.endif
# depends on flim
BUILD_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:editors/flim${DEPPORT_SUFFIX}
RUN_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:editors/flim${DEPPORT_SUFFIX}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

.if !defined(BUILD_INFO_BY_EMACS) || (${BUILD_INFO_BY_EMACS} == "NO")
# info files JIS to EUC
BUILD_DEPENDS+=	nkf:japanese/nkf
.endif

MAKEINFO=		makeinfo --no-split --no-validate
MAKEINFO_EMACS=		${EMACS_CMD} -no-site-file -no-init-file -batch
MAKEINFO_EMACS_FLAGS=	-e texinfo-format-buffer -f save-buffer

.if ! defined(EMACS_PACKAGESDIR) || ! defined(MANIFEST)
INFO=		mime-ui-en
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
INFO+=		mime-ui-ja
.endif
.endif

post-build:
.if defined(BUILD_INFO_BY_EMACS) && (${BUILD_INFO_BY_EMACS} == "YES")
	@${MAKE} -C ${.CURDIR} info-build-by-emacs
.else
	@${MAKE} -C ${.CURDIR} info-build
.endif

pre-install:
.if defined(EMACS_PACKAGESDIR) && defined(EMACS_PACKAGES_SUBDIRS)
	@${MAKE} -C ${.CURDIR} mkdir-site-packages
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/semi
	@${TOUCH} ${STAGEDIR}${LOCALBASE}/share/semi/${SEMI_COOKIE}
.if defined(EMACS_PACKAGESDIR) && defined(MANIFEST)
	@${MAKE} -C ${.CURDIR} info-package-install
	@${MAKE} -C ${.CURDIR} manifest-install
.else
	@${MAKE} -C ${.CURDIR} info-install
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MAKE} -C ${.CURDIR} doc-install
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

mkdir-site-packages:
	@(for i in ${EMACS_PACKAGES_SUBDIRS} ; do \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/${EMACS_PACKAGESDIR}/$${i} ; \
	done)

doc-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/${SEMIDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${LOCALBASE}/${SEMIDOCDIR}/ ; \
	done)

info-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${LOCALBASE}/info ; \
	done)
.if defined(EMACS_HAS_MULE) && (${EMACS_HAS_MULE} == "YES")
	@(cd ${WRKSRC} ; \
	for i in mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${LOCALBASE}/info ; \
	done)
.endif

info-package-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${STAGEDIR}${LOCALBASE}/${EMACS_PACKAGESDIR}/info ; \
	done ; \
	${MKDIR} ${STAGEDIR}${LOCALBASE}/${EMACS_PACKAGESDIR}/man/semi ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${STAGEDIR}${LOCALBASE}/${EMACS_PACKAGESDIR}/man/semi ; \
	done)

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PLIST} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${STAGEDIR}${LOCALBASE}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
