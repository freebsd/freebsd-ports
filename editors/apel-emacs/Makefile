# New ports collection makefile for:	apel for emacs
# Version required:	9.22
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	apel-${APEL_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/apel/ \
		ftp://ftp.center.osaka-u.ac.jp/mule/apel/

MAINTAINER?=	shige@FreeBSD.org

# distfile version
APEL_VER=	9.22
# setupel filename
APEL_SETUPEL=	apel-setupel.el
# document install directory by install-doc target
APELDOCDIR?=	share/doc/apel

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}
# emacs requires *-setupel.el
REQUIRE_SETUPEL=  YES
.endif

# target name for make build
ALL_TARGET?=	elc

.if defined(EMACS_PORT)
PKGNAME=	apel-${EMACS_PORT}-${APEL_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif

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
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR, EMACS_LIBDIR_WITH_VER."
	@${FALSE}
.endif

pre-configure:
.if defined(REQUIRE_SETUPEL) && (${REQUIRE_SETUPEL} == "YES")
	@${CP} ${FILESDIR}/${APEL_SETUPEL}.in ${WRKDIR}
.endif

pre-install:
.if defined(EMACS_PACKAGESDIR) && defined(EMACS_PACKAGES_SUBDIRS)
	@${MAKE} mkdir-site-packages
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

.include <bsd.port.mk>
