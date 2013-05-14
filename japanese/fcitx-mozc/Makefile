# Created by: Daichi GOTO <daichi@freebsd.org>
# $FreeBSD$

PKGNAMEPREFIX=	ja-fcitx-

COMMENT=	Mozc engine for Fcitx
DATADIR=	${PREFIX}/share/fcitx/${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
PKGMESSAGE=	${.CURDIR}/pkg-message

BROKEN=		fails to build

BUILD_MOZC_LIST=	fcitx_mozc

.include "${MASTERDIR}/Makefile"
