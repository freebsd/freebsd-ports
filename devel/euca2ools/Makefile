# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	euca2ools
PORTVERSION=	3.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Eucalyptus Command Line Tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requestbuilder>=0.6:www/py-requestbuilder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.8:devel/py-six@${PY_FLAVOR}

USES=		python:2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	eucalyptus

NO_ARCH=	yes

.include <bsd.port.mk>
