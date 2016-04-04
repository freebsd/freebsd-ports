# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	euca2ools
PORTVERSION=	3.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Eucalyptus Command Line Tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}requestbuilder>=0.4:www/py-requestbuilder \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six

USES=		python:2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	eucalyptus

NO_ARCH=	yes

.include <bsd.port.mk>
