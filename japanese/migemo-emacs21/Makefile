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

USE_EMACS=	yes
EMACS_PORT_NAME=	emacs21
BUILD_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME} \
		migemo:${PORTSDIR}/japanese/migemo

CONFLICTS=	ja-migemo-emacs22-[0-9]*

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""
SLAVE_PORT=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${PREFIX}/${EMACS_LIBDIR}/site-lisp
.include "${MASTERDIR}/Makefile"
