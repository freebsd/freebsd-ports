# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics java
PKGNAMESUFFIX=	-${OCV_SLAVE}

COMMENT=	OpenCV Java library

OCV_SLAVE=	java
OCV_JAVA=	yes
MASTERDIR=	${.CURDIR:H}/opencv
PLIST=		${.CURDIR}/pkg-plist

PLIST_SUB+=	OCV_VER=${DISTVERSION:S|.||g}

.include "${MASTERDIR}/Makefile"
