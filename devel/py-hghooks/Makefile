# New ports collection makefile for:	py-hghooks
# Date created:				04 May 2012
# Whom:					William Grzybowski
#
# $FreeBSD$
#

PORTNAME=	hghooks
PORTVERSION=	0.5.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	william88@gmail.com
COMMENT=	Set of Mercurial hooks

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
