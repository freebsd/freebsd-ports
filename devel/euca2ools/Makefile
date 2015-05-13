# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	euca2ools
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Eucalyptus Command Line Tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}requestbuilder>=0.2.0:${PORTSDIR}/www/py-requestbuilder \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:${PORTSDIR}/devel/py-six

USE_GITHUB=	yes
GH_ACCOUNT=	eucalyptus

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
