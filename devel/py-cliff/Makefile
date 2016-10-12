# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	cliff
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Command Line Interface Formulation Framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cmd2>=0.6.7:devel/py-cmd2 \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}unicodecsv>=0.8.0:devel/py-unicodecsv \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.1.0:devel/py-yaml

NO_ARCH=	yes

USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
