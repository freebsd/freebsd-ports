# New ports collection makefile for:	apel for emacs
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	apel
PORTVERSION=	${APEL_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/apel/ \
		ftp://ftp.jpl.org/pub/elisp/apel/ \
		ftp://ftp.etl.go.jp/pub/mule/apel/ \
		ftp://ftp.media.kyoto-u.ac.jp/pub/mule/apel/ \
		ftp://ftp.win.or.jp/pub/word/mule/apel/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/emacs/mule/apel/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A Portable Emacs Library for emacs21

# distfile version
APEL_VER=	10.6
# setupel filename
APEL_SETUPEL=	apel-setupel.el
# document install directory by install-doc target
APELDOCDIR?=	share/doc/apel
# apel lispdir
APEL_LISPDIR?=			${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
APEL_VERSION_SPECIFIC_LISPDIR?=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs21
.endif

EMACS_MASTERDIR_PKGFILES=YES

# target name for make build
ALL_TARGET?=	elc
# environments
SCRIPTS_ENV+=	TARGETS="${APEL_SETUPEL}"
PLIST_SUB+=	APELDOCDIR=${APELDOCDIR} APEL_SETUPEL=${APEL_SETUPEL}
MAKE_ARGS+=	PREFIX="${LOCALBASE}" \
		LISPDIR="${APEL_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${APEL_VERSION_SPECIFIC_LISPDIR}"

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
# depends on custom: emacs-19.34 or mule-19.34
.if (${EMACS_VER} == "19.34")
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_NAME}
.endif
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/xemacs-base/advice.el:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/xemacs-base/advice.el:${PORTSDIR}/editors/xemacs-packages
.endif
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

pre-configure:
.if defined(EMACS_NO_SUBDIRSEL) && (${EMACS_NO_SUBDIRSEL} == "YES")
	@${CP} ${FILESDIR}/${APEL_SETUPEL}.in ${WRKDIR}
.endif

pre-install:
.if defined(EMACS_PACKAGESDIR) && defined(EMACS_PACKAGES_SUBDIRS)
	@${MAKE} mkdir-site-packages
.endif
.if defined(EMACS_PACKAGESDIR) && defined(XEMACS_PKGNAME)
	@${MAKE} pkg-el-install
.endif

post-install:
.if defined(EMACS_NO_SUBDIRSEL) && (${EMACS_NO_SUBDIRSEL} == "YES")
	@${MAKE} setupel-install
.endif
.if defined(EMACS_PACKAGESDIR) && defined(MANIFEST)
	@${MAKE} manifest-install
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} doc-install
.endif

###############################################################################
#
# local functions
#
mkdir-site-packages:
	@(for i in ${EMACS_PACKAGES_SUBDIRS} ; do \
	    ${MKDIR} ${LOCALBASE}/${EMACS_PACKAGESDIR}/$${i} ; \
	done)

pkg-el-install:
	@(if [ -f ${FILESDIR}/_pkg.el ] ; then \
	${MKDIR} ${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME} ;\
	${INSTALL_DATA} ${FILESDIR}/_pkg.el \
	    ${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME}/_pkg.el ;\
	fi)

doc-install:
	@${MKDIR} ${LOCALBASE}/${APELDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
	    ${INSTALL_DATA} $${i} ${LOCALBASE}/${APELDOCDIR}/ ; \
	done)

setupel-install:
	@${INSTALL_DATA} ${WRKDIR}/${APEL_SETUPEL} \
			${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PLIST} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${LOCALBASE}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
