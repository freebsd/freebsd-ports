# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	ja-fcitx-

COMMENT=	Mozc engine for Fcitx

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15
DATADIR=	${PREFIX}/share/fcitx/${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
FILESDIR=	${.CURDIR}/files
SUB_FILES=	pkg-message

BUILD_MOZC_LIST=	fcitx_mozc

.include "${MASTERDIR}/Makefile"
