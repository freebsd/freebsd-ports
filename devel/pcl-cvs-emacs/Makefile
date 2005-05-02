# New ports collection makefile for:	pcl-cvs for GNU Emacs 19
# Date created:		18 Apr 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	pcl-cvs
PORTVERSION=	2.9.9
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	okazaki/pcl-cvs
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DIST_SUBDIR=	pcl-cvs

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	okazaki/pcl-cvs
PATCHFILES=	pcl-cvs-2.9.9-compat.patch

MAINTAINER?=	okazaki@FreeBSD.org
COMMENT=	An Emacs-based front-end to CVS

# startup el filename
PORT_SETUPEL=	pcl-cvs-setup.el

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs19
CUSTOM_PORT_SUFFIX=	-emacs
.endif
ELIB_PORT_SUFFIX?=	-${EMACS_PORT_NAME}

# target name for make build
ALL_TARGET?=		elcfiles info
INSTALL_TARGET?=	install_el install_elc install_info
INSTALL_TARGET+=	install_startup

INFO=	pcl-cvs

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog FAQ NEWS README TODO
.endif

.if ${EMACS_VER} == "19.34"
EASY_MMODE=	easy-mmode.el
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${EXTRACT_ONLY} ${EASY_MMODE}
ELIB_SETUP=	'(if (locate-library "elib-startup") (require '\''elib-startup))'
.endif

PLIST_SUB+=	PORT_SETUPEL=${PORT_SETUPEL}
MAKE_ARGS+=	EMACS="${EMACS_CMD} -q --no-site-file" \
		CP="${INSTALL_DATA}" \
		MAKEINFO="makeinfo --no-split" \
		MKDIR="${MKDIR}" \
		prefix="${PREFIX}" \
		lispdir="${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		startupfile="${PORT_SETUPEL}"

.if defined(EMACS_PORT_NAME)
ELIB_PORTDIR=	${PORTSDIR}/devel/elib${ELIB_PORT_SUFFIX}
BUILD_DEPENDS+=	${EMACS_BASE}/${EMACS_VERSION_SITE_LISPDIR}/elib/cookie.el:${ELIB_PORTDIR}
RUN_DEPENDS+=	${EMACS_BASE}/${EMACS_VERSION_SITE_LISPDIR}/elib/cookie.el:${ELIB_PORTDIR}
.if (${EMACS_VER} == "19.34")
CUSTOM_PORTDIR=	${PORTSDIR}/editors/custom${CUSTOM_PORT_SUFFIX}
# depends on custom: emacs-19.34 or mule-2.3 based on emacs-19.34
BUILD_DEPENDS+=	${EMACS_BASE}/${EMACS_VERSION_SITE_LISPDIR}/custom.el:${CUSTOM_PORTDIR}
RUN_DEPENDS+=	${EMACS_BASE}/${EMACS_VERSION_SITE_LISPDIR}/custom.el:${CUSTOM_PORTDIR}
.else
# diff-mode.el does not run on emacs-19.34
RUN_DEPENDS+=	${EMACS_BASE}/${EMACS_SITE_LISPDIR}/diff-mode.el:${PORTSDIR}/textproc/diff-mode.el
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
	${ECHO_CMD} "(provide 'pcl-cvs-startup)" >> ${WRKSRC}/pcl-cvs-startup.el

pre-install:
	-${RM} ${INSTALL_WRKSRC}/${PORT_SETUPEL}
.if defined(ELIB_SETUP) && !empty(ELIB_SETUP)
	${ECHO_CMD} ${ELIB_SETUP} >> ${INSTALL_WRKSRC}/${PORT_SETUPEL}
.endif

POST_INSTALL_SEQ+=	setupel-install
.if !defined(NOPORTDOCS)
POST_INSTALL_SEQ+=	doc-install
.endif

post-install: ${POST_INSTALL_SEQ}
	@${CAT} ${PKGMESSAGE}

doc-install:
	${MKDIR} ${DOCSDIR}
	cd ${INSTALL_WRKSRC} && \
	for i in ${PORTDOCS}; do \
		${INSTALL_DATA} $${i} ${DOCSDIR} ; \
	done

setupel-install:
	${ECHO_CMD} "(provide 'pcl-cvs-setup)" >> ${INSTALL_WRKSRC}/${PORT_SETUPEL}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORT_SETUPEL} \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/

.include <bsd.port.post.mk>
