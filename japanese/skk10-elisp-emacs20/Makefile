# New ports collection makefile for:	skk10-elisp-emacs20
# Version required:	10.55
# Date created:		21 September 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	skk${SKK10_VER}
PKGNAME=	ja-skk-elisp-${EMACS_PORT_NAME}-${SKK10_VER}
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.asahi-net.or.jp/~gy2m-nkjm/skk/

MAINTAINER?=	shige@FreeBSD.org

SKK10_VER=	10.55

# This port is a master port.
PORT_CLASS?=	master

.if (${PORT_CLASS} == "master")
# emacsen-port-name
EMACS_PORT_NAME=	emacs20
# emacsen-information
EMACS_NAME=		emacs
EMACS_VER=		20.4
EMACS_CMD=		${LOCALBASE}/bin/${EMACS_NAME}-${EMACS_VER}
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}
# Whether emacs requires *-setupel.el
REQUIRE_SETUPEL=	NO
# Whether emacs port has *-common port
HAVE_COMMON_PORT=	NO
.endif

# dependency: skk-jisyo
RUN_DEPENDS+=	${LOCALBASE}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}
# dependency: apel
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
# dependency: emacsen
BUILD_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}-common
.else
RUN_DEPENDS+=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}
.endif

WRKSRC=		${WRKDIR}/skk-${SKK10_VER}
ALL_TARGET?=	elc
MAKE_ARGS=	EMACS=${EMACS_CMD}
PLIST_SUB=	EMACS=${EMACS_CMD} EMACS_LIBDIR=${EMACS_LIBDIR}

# information of skk-jisyo
SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

post-install:
	@install-info ${PREFIX}/info/skk.info ${PREFIX}/info/dir

.include <bsd.port.mk>
