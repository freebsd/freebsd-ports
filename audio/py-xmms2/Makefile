# New ports collection makefile for:	py-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTREVISION=	5

CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Bindings for XMMS2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pyrex/__init__.py:${PORTSDIR}/devel/pyrex
LIB_DEPENDS+=	xmmsclient.6:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_PYTHON=	yes

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	python

.include "${MASTERDIR}/Makefile"
