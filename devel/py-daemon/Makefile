# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	daemon
PORTVERSION=	1.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-daemon-${PORTVERSION}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Well-behaved daemon framework for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>=0.9:${PORTSDIR}/devel/py-lockfile
RUN_DEPENDS:=	${BUILD_REPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
