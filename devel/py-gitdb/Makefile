# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	gitdb
PORTVERSION=	0.6.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Python git object database

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async>=0.6.1:${PORTSDIR}/devel/py-async \
		${PYTHON_PKGNAMEPREFIX}smmap>=0.8.5:${PORTSDIR}/devel/py-smmap

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
