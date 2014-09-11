# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/py-gobject3/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTREVISION=	2

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

COMMENT=	Python 2 bindings for GObject

SLAVE_PORT=	python2

MASTERDIR=	${.CURDIR}/../../devel/pygobject3-common
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"

PLIST_SUB+=	UNAME_M=${UNAME_M}
UNAME_M!=       ${UNAME} -m
