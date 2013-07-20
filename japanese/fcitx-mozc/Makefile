# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	ja-fcitx-

COMMENT=	Mozc engine for Fcitx
DATADIR=	${PREFIX}/share/fcitx/${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
PKGMESSAGE=	${.CURDIR}/pkg-message

BUILD_MOZC_LIST=	fcitx_mozc

IGNORE=	not compatible with mozc 1.11.1502.102

.include "${MASTERDIR}/Makefile"
