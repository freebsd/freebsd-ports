# New ports collection makefile for:   Migemo (for xemacs-devel-mule)
# Date Created:			24 Mar 2001
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
COMMENT=	Japanese incremental search tool for xemacs-devel-mule
MASTERDIR=	${.CURDIR}/../../japanese/migemo
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist
PKGMESSAGE=	${MASTERDIR}/pkg-message

EMACS_PORT_NAME=	xemacs-devel-mule

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""

do-install:
	${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${PREFIX}/${EMACS_SITE_LISPDIR}

.include "${MASTERDIR}/Makefile"
