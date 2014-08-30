# Created by: Denis Podolskiy <bytestore@yandex.ru>
# $FreeBSD$

PORTREVISION?=	3

PKGNAMEPREFIX=	lib

COMMENT=	SIMD-accelerated JPEG codec library, provides libTurboJPEG

MASTERDIR=	${.CURDIR:H}/jpeg-turbo
SLAVE_PORT=	yes
OPTIONS_EXCLUDE=DOCS EXAMPLES
OPTIONS_SLAVE=	PIC

.include "${MASTERDIR}/Makefile"
