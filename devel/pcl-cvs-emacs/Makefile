# New ports collection makefile for:	pcl-cvs for GNU Emacs 19
# Date created:		18 Apr 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	pcl-cvs
PORTVERSION=	2.9.9
CATEGORIES=	devel elisp
MASTER_SITES=	ftp://rum.cs.yale.edu/pub/monnier/pcl-cvs/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DIST_SUBDIR=	pcl-cvs

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR= okazaki/pcl-cvs
PATCHFILES=	pcl-cvs-2.9.9-compat.patch

MAINTAINER?=	okazaki@FreeBSD.org

IGNORE=	"is broken until restructuring of the elib port finishes"
# startup el filename
PORT_SETUPEL=	pcl-cvs-setup.el
# document install directory by install-doc target
PORTDOCDIR?=	share/doc/pcl-cvs

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs
.endif

# target name for make build
ALL_TARGET?=		elcfiles info
INSTALL_TARGET?=	install_el install_elc install_info
INSTALL_TARGET+=	install_startup

.include <bsd.port.pre.mk>

.if ${EMACS_VER} == "19.34"
EASY_MMODE=	easy-mmode.el
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${EXTRACT_ONLY} ${EASY_MMODE}
ELIB_SETUP=	'(if (locate-library "elib-startup") (require '\''elib-startup))'
.endif

PLIST_SUB+=	PORTDOCDIR=${PORTDOCDIR} \
		PORT_SETUPEL=${PORT_SETUPEL}
MAKE_ARGS+=	EMACS="${EMACS_CMD} -q --no-site-file" \
		CP="${INSTALL_DATA}" \
		MAKEINFO="makeinfo --no-split" \
		MKDIR="${MKDIR}" \
		prefix="${PREFIX}" \
		lispdir="${PREFIX}/${EMACS_SITE_LISPDIR}" \
		startupfile="${PORT_SETUPEL}"

.if defined(EMACS_PORT_NAME)
ELIB_PORTDIR=	${PORTSDIR}/devel/elib-${EMACS_PORT_NAME}
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/elib/cookie.el:${ELIB_PORTDIR}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/elib/cookie.el:${ELIB_PORTDIR}
.if (${EMACS_VER} == "19.34")
# depends on custom: emacs-19.34 or mule-2.3 based on emacs-19.34
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT_NAME}
.else
# diff-mode.el does not run on emacs-19.34
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/diff-mode.el:${PORTSDIR}/textproc/diff-mode.el
.endif
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

post-extract:
.if defined(EASY_MMODE)
	${CP} ${_DISTDIR}/${EASY_MMODE} ${WRKSRC}
.endif

pre-build:
	${RM} ${WRKSRC}/pcl-cvs.info*

post-build:
	${ECHO} "(provide 'pcl-cvs-startup)" >> ${WRKSRC}/pcl-cvs-startup.el

pre-install:
.if defined(ELIB_SETUP) && !empty(ELIB_SETUP)
	${ECHO} ${ELIB_SETUP} >> ${INSTALL_WRKSRC}/${PORT_SETUPEL}
.endif

post-install:
	${ECHO} "(provide 'pcl-cvs-setup)" >> ${INSTALL_WRKSRC}/${PORT_SETUPEL}
	@${MAKE} setupel-install
.if !defined(NOPORTDOCS)
	@${MAKE} doc-install
.endif
	@${CAT} ${PKGMESSAGE}

doc-install:
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
	cd ${INSTALL_WRKSRC} && \
	for i in ChangeLog FAQ NEWS README TODO; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${PORTDOCDIR}/ ; \
	done

setupel-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORT_SETUPEL} \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/

.include <bsd.port.post.mk>
