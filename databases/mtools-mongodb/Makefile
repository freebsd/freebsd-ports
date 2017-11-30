# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtools
PORTVERSION=	1.2.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-mongodb

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Setup test environments; parse, filter and visualize MongoDB log files

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=2.0:sysutils/py-psutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/pymongo \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${FLAVOR}

USE_PYTHON=	autoplist distutils
USES=		python:2

.include <bsd.port.mk>
