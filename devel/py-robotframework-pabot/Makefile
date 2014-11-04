# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-pabot
PORTVERSION=	0.11
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Parallel executor for Robot Framework test cases

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:${PORTSDIR}/devel/py-robotframework \
		${PYTHON_PKGNAMEPREFIX}robotremoteserver>=1.0.1:${PORTSDIR}/devel/py-robotremoteserver

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
