# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-pabot
PORTVERSION=	0.34
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Parallel executor for Robot Framework test cases

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:devel/py-robotframework \
		${PYTHON_PKGNAMEPREFIX}robotremoteserver>=1.0.1:devel/py-robotremoteserver

NO_ARCH=	yes
USES=		python:-2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
