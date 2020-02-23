# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTREVISION=	6

CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Python Bindings for XMMS2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyrex>0:devel/pyrex@${PY_FLAVOR}
LIB_DEPENDS+=	libxmmsclient.so:audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USES=		python:2.7 ssl
USE_PYTHON=	flavors

BROKEN_SSL=	openssl

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	python

.include "${MASTERDIR}/Makefile"
