# New ports collection makefile for:	py-ipaddr
# Date created:		2008-10-03
# Whom:			Murilo Opsfelder <mopsfelder@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ipaddr
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	http://ipaddr-py.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	A Google open source IPv4/IPv6 manipulation library in Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	ipaddr

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/ipaddr.py \
		%%PYTHON_SITELIBDIR%%/ipaddr.pyc \
		%%PYTHON_SITELIBDIR%%/ipaddr.pyo

.include <bsd.port.mk>
