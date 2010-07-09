# New ports collection makefile for: python-daemon
# Date created: 7 Jul 2010
# Whom:			jessekempf@gmail.com
# $FreeBSD$
#

PORTNAME=	daemon
PORTVERSION=	1.5.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-daemon-${PORTVERSION}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Well-behaved daemon framework for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>0:${PORTSDIR}/devel/py-lockfile

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME =	python-daemon
PYDISTUTILS_NOEGGINFO =	yes

.include <bsd.port.mk>
