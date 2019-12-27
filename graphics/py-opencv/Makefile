# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	OpenCV Python library

BROKEN_armv7=		fails to build: make[1]: cannot open Makefile

OCV_SLAVE=	python
OCV_PYTHON=	yes
MASTERDIR=	${.CURDIR:H}/opencv
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
