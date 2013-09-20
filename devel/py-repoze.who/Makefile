# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.who
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An identification and authentication framework for WSGI

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.5.2:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
