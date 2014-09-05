# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}logilab-common>0:${PORTSDIR}/devel/py-logilab-common

USES=		python zip
MAKE_ENV=	NO_SETUPTOOLS=1
USE_PYTHON=	distutils

.include <bsd.port.pre.mk>

post-patch:
	@${CHMOD} a+r ${WRKSRC}/brain/*.py

.include <bsd.port.post.mk>
