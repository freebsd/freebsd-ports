# New ports collection makefile for:	Migemo (for emacs21)
# Date created:		8 Nov 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
COMMENT=	Japanese incremental search tool for emacs21
MASTERDIR=	${.CURDIR}/../../japanese/migemo
PKGDIR=	${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist
PKGMESSAGE=	${MASTERDIR}/pkg-message

EMACS_PORT_NAME=	emacs21
BUILD_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel
RUN_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel \
		migemo:${PORTSDIR}/japanese/migemo

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${PREFIX}/${EMACS_LIBDIR}/site-lisp
.include "${MASTERDIR}/Makefile"
