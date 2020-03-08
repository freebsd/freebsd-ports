# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	ja-ibus-

COMMENT=	Mozc engine for IBus

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15
DATADIR=	${PREFIX}/share/ibus-${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
FILESDIR=	${.CURDIR}/files
SUB_FILES=	pkg-message

BUILD_MOZC_LIST=	ibus_mozc

.include "${MASTERDIR}/Makefile"
