# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.what-pylons
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	The repoze.what v1 plugin for Pylons/TG2 integration

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons>=0.9.7:${PORTSDIR}/www/py-pylons \
		${PYTHON_PKGNAMEPREFIX}repoze.what>=0:${PORTSDIR}/devel/py-repoze.what \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.5.2:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
