# New ports collection makefile for:	Elib for GNU Emacs 21
# Date created:		24 Feb 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	elib
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	okazaki@FreeBSD.org

# setupel filename
PORT_SETUPEL=	elib-startup.el

# This is a master port.
PORTCLASS?=	master

# emacs port setup
.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs21
.endif

# target name for make build
ALL_TARGET?=	all

.include <bsd.port.pre.mk>

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
	@${ECHO} "(provide 'elib-startup)" >> ${WRKSRC}/${PORT_SETUPEL}

post-install:
.if defined(INSTALL_LOADPATHSETUP)
	@${MAKE} setupel-install
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} doc-install
.endif
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

doc-install:
	${MKDIR} ${DOCSDIR}
	cd ${INSTALL_WRKSRC} && \
	for i in ChangeLog NEWS README ; do \
		${INSTALL_DATA} $${i} ${DOCSDIR} ; \
	done

setupel-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORT_SETUPEL} \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/

.include <bsd.port.post.mk>
