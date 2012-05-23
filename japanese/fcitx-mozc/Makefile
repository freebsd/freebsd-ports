# New ports collection makefile for:	fcitx-mozc
# Date created:				22 May 2012
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	ja-fcitx-
PKGNAMESUFFIX=
COMMENT=	Mozc engine for Fcitx
DATADIR=	${PREFIX}/share/fcitx/${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
PKGMESSAGE=	${.CURDIR}/pkg-message

BUILD_MOZC_LIST=	fcitx_mozc

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include "${MASTERDIR}/Makefile"
