# New ports collection makefile for:	Migemo (for emacs20)
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
COMMENT=	Japanese incremental search tool for emacs20
MASTERDIR=      ${.CURDIR}/../../japanese/migemo
PKGDIR=         ${.CURDIR}
PLIST=          ${MASTERDIR}/pkg-plist
PKGMESSAGE=     ${MASTERDIR}/pkg-message

EMACS_PORT_NAME=	emacs20
BUILD_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME} \
		migemo:${PORTSDIR}/japanese/migemo

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${PREFIX}/${EMACS_LIBDIR}/site-lisp
.include "${MASTERDIR}/Makefile"
