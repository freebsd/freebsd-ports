# New ports collection makefile for:	psgml for emacs
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	psgml
PORTVERSION=	1.3.2
PORTREVISION=	17
CATEGORIES=	editors elisp
MASTER_SITES=	SF/${PORTNAME}/ALPHA%20${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	hrs
PATCHFILES=	psgml-symbol-conflict-050503.diff.gz

MAINTAINER?=	hrs@FreeBSD.org
COMMENT=	A major mode for editing SGML and XML documents for ${EMACS_PORT_NAME}

SUB_FILES=	${PSGML_STARTUPEL}
SUB_LIST=	PSGML_LISPDIR=${PSGML_LISPDIR}
PLIST_SUB=	PSGML_STARTUPEL=${PSGML_STARTUPEL}
NOT_FOR_ARCHS=	ia64
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--lispdir=${PSGML_LISPDIR}
CONFIGURE_ENV=	EMACS=${EMACS_CMD}
USE_EMACS=	yes

POSTPATCHES=	${FILESDIR}/post-patch-*

INFO=		psgml psgml-api

PSGML_STARTUPEL=	psgml-startup.el
PSGML_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/psgml

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} == xemacs21-mule
PLIST_SUB+=	XEMACS="" \
		NON_XEMACS="@comment "
.else
PLIST_SUB+=	XEMACS="@comment " \
		NON_XEMACS=""
.endif

post-patch:
	cd ${PATCH_WRKSRC} && ${CAT} ${POSTPATCHES} | ${PATCH}

post-install:
	cd ${WRKSRC} && ${MAKE} install-info
	${INSTALL_DATA} ${WRKDIR}/${PSGML_STARTUPEL} \
			${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.post.mk>
