# New ports collection makefile for:	apel for emacs
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	apel-${EMACS_PORT_NAME}
PORTVERSION=	${APEL_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/apel/ \
		ftp://ftp.center.osaka-u.ac.jp/mule/apel/
DISTNAME=	apel-${APEL_VER}

MAINTAINER?=	shige@FreeBSD.org

# distfile version
APEL_VER=	10.2
# setupel filename
APEL_SETUPEL=	apel-setupel.el
# document install directory by install-doc target
APELDOCDIR?=	share/doc/apel

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs
# emacs requires *-setupel.el
REQUIRE_SETUPEL=  YES
.endif

.include <bsd.port.pre.mk>

# target name for make build
ALL_TARGET?=	elc

# depends on custom: emacs-19.34 or mule-19.34
.if (${EMACS_VER} == "19.34")
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
.endif
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/xemacs-packages/lisp/xemacs-base/advice.el:${PORTSDIR}/editors/xemacs-sumo-packages
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/xemacs-packages/lisp/xemacs-base/advice.el:${PORTSDIR}/editors/xemacs-sumo-packages
.endif

SCRIPTS_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		TARGETS="${APEL_SETUPEL}"
PLIST_SUB+=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		APELDOCDIR=${APELDOCDIR} APEL_SETUPEL=${APEL_SETUPEL}
MAKE_FLAGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD}

pre-configure:
.if defined(REQUIRE_SETUPEL) && (${REQUIRE_SETUPEL} == "YES")
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
.if defined(REQUIRE_SETUPEL) && (${REQUIRE_SETUPEL} == "YES")
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
		${MKDIR} ${PREFIX}/${EMACS_PACKAGESDIR}/$${i} ; \
	done)

pkg-el-install:
	@(if [ -f ${FILESDIR}/_pkg.el ] ; then \
	${MKDIR} ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME} ;\
	${INSTALL_DATA} ${FILESDIR}/_pkg.el \
		${PREFIX}/${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME}/_pkg.el ;\
	fi)

doc-install:
	@${MKDIR} ${PREFIX}/${APELDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${APELDOCDIR}/ ; \
	done)

setupel-install:
	@${INSTALL_DATA} ${WRKDIR}/${APEL_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp

manifest-install:
	@${RM} -f ${WRKDIR}/${MANIFEST}
	@${CAT} ${PKGDIR}/PLIST | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s;^%%EMACS_PACKAGESDIR%%/;;" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/

.include <bsd.port.post.mk>
