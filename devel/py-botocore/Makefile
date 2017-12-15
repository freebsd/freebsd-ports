# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	botocore
PORTVERSION=	1.8.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	Low-level, core functionality of boto 3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1:devel/py-jmespath@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
