# New ports collection makefile for:   Migemo (for xemacs21-mule)
# Date Created:			24 Mar 2001
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
COMMENT=	Japanese incremental search tool for xemacs21-mule
MASTERDIR=      ${.CURDIR}/../../japanese/migemo
PKGDIR=         ${.CURDIR}
PLIST=          ${MASTERDIR}/pkg-plist
PKGMESSAGE=     ${MASTERDIR}/pkg-message

EMACS_PORT_NAME=	xemacs21-mule
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
BUILD_DEPENDS=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/apel/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME} \
		migemo:${PORTSDIR}/japanese/migemo

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_LIBDIR}/site-lisp
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${PREFIX}/${EMACS_LIBDIR}/site-lisp
.include "${MASTERDIR}/Makefile"
