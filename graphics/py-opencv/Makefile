# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	OpenCV Python library

OCV_SLAVE=	python
OCV_PYTHON=	yes
MASTERDIR=	${.CURDIR:H}/opencv
PLIST=		${.CURDIR}/pkg-plist

.if defined(PYTHON_REL) && ${PYTHON_REL} >= 320
PLIST_SUB+=	PYTHON3="" \
		PYTHON2="@comment " \
		PYTHON_SUFFIX="${PYTHON_SUFFIX}"
.else
PLIST_SUB+=	PYTHON3="@comment " \
		PYTHON2=""
.endif

.include "${MASTERDIR}/Makefile"
