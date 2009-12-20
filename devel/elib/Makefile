# New ports collection makefile for:	Elib for GNU Emacs 21
# Date created:		24 Feb 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	elib
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	../old-gnu/emacs
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Collection of useful routines for Emacs lisp programs

# setupel filename
PORT_SETUPEL=	elib-startup.el

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
USE_EMACS=	yes
.endif

# target name for make build
ALL_TARGET?=	all

INFO=	elib

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog NEWS README
.endif

PLIST_SUB+=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		PORT_SETUPEL=${PORT_SETUPEL}
MAKE_ARGS+=	EMACS="${EMACS_CMD} -q --no-site-file" \
		INSTALL_DATA="${INSTALL_DATA}" \
		MAKEINFO="makeinfo --no-split" \
		MKDIR="${MKDIR}" \
		prefix="${PREFIX}" \
		locallisppath="${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}"

.if defined(EMACS_PORT_NAME)
.if ${EMACS_MAJOR_VER} <= 19
INSTALL_LOADPATHSETUP=	yes
PKGMESSAGE=	${PKGDIR}/pkg-message.emacs19
PLIST_SUB+=	LOADPATHSETUP:=""
.else
PLIST_SUB+=	LOADPATHSETUP:="@comment "
.endif
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

post-build:
	@${ECHO_CMD} "(provide 'elib-startup)" >> ${WRKSRC}/${PORT_SETUPEL}

.if defined(INSTALL_LOADPATHSETUP)
POST_INSTALL_SEQ+=	setupel-install
.endif
.if !defined(NOPORTDOCS)
POST_INSTALL_SEQ+=	doc-install
.endif

post-install: ${POST_INSTALL_SEQ}
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

doc-install:
	${MKDIR} ${DOCSDIR}
	cd ${INSTALL_WRKSRC} && \
	for i in ${PORTDOCS} ; do \
		${INSTALL_DATA} $${i} ${DOCSDIR} ; \
	done

setupel-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORT_SETUPEL} \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/

.include <bsd.port.post.mk>
