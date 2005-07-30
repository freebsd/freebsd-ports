# New ports collection makefile for:	psgml for emacs
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	psgml
PORTVERSION=	1.3.2
PORTREVISION=	3
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	psgml
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	hrs
PATCHFILES=	psgml-symbol-conflict-050503.diff.gz

MAINTAINER?=	hrs@FreeBSD.org
COMMENT?=	A major mode for editing SGML and XML documents for emacs21

INFO=		psgml psgml-api

PSGML_STARTUPEL=	psgml-startup.el

SUB_FILES=	${PSGML_STARTUPEL}
SUB_LIST=	PSGML_LISPDIR=${PSGML_LISPDIR}
PLIST_SUB=	PSGML_STARTUPEL=${PSGML_STARTUPEL}
NOT_FOR_ARCHS=	ia64

# This is a master port.
EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} == xemacs21-mule
PLIST_SUB+=	XEMACS="" \
		NON_XEMACS="@comment "
.else
PLIST_SUB+=	XEMACS="@comment " \
		NON_XEMACS=""
.endif

.include <bsd.port.pre.mk>

#
# emacs ports setup
#
.if defined(EMACS_PORT_NAME)
PSGML_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/psgml
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--lispdir=${PSGML_LISPDIR} \
		--infodir=${PREFIX}/${INFO_PATH}
CONFIGURE_ENV=	EMACS=${EMACS_CMD}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

post-install:
	cd ${WRKSRC} && ${MAKE} install-info
	${INSTALL_DATA} ${WRKDIR}/${PSGML_STARTUPEL} \
			${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.post.mk>
