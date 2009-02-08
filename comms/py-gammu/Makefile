# New ports collection makefile for:	py-gammu
# Date created:		03 Feb,2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	0.28
CATEGORIES=	comms python
MASTER_SITES=	http://dl.cihar.com/python-gammu/latest/ \
		http://mirror.clickcreations.com/python-gammu/latest/ \
		http://dl.cihar.com.nyud.net/python-gammu/latest/ \
		ftp://dl.cihar.com/python-gammu/latest/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python bindings for Gammu library

BUILD_DEPENDS=	${LOCALBASE}/bin/gammu:${PORTSDIR}/comms/gammu

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_${PORTNAME}

.include <bsd.port.mk>
