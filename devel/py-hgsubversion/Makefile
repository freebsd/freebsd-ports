# New ports collection makefile for:	hgsubversion
# Date created:				07 May 2012
# Whom:					William Grzybowski
#
# $FreeBSD$
#

PORTNAME=	hgsubversion
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	william88@gmail.com
COMMENT=	Mercurial extension that allows using it as a Subversion client

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>=0:${PORTSDIR}/devel/py-subversion \
	${PYTHON_PKGNAMEPREFIX}subvertpy>=0:${PORTSDIR}/devel/py-subvertpy

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
