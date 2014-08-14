# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/logilab/astroid/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-1.1

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

LICENSE=	LGPL21

RUN_DEPENDS=	pytest:${PORTSDIR}/devel/py-logilab-common

USES=		python
WRKSRC=		${WRKDIR}/logilab-astroid-e003574ae51b
MAKE_ENV=	NO_SETUPTOOLS=1
USE_PYTHON=	distutils

.include <bsd.port.pre.mk>

post-patch:
	@${CHMOD} a+r ${WRKSRC}/brain/*.py

.include <bsd.port.post.mk>
