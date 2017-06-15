# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	traceback2
PORTVERSION=	1.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	New features in traceback backported to Python 2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-pbr

LICENSE=	PSFL

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
