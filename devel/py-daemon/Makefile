# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	daemon
PORTVERSION=	1.5.5
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-daemon-${PORTVERSION}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Well-behaved daemon framework for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>=0.9:${PORTSDIR}/devel/py-lockfile
RUN_DEPENDS:=	${BUILD_REPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME =	python-daemon
PYDISTUTILS_NOEGGINFO =	yes

NO_STAGE=	yes
.include <bsd.port.mk>
