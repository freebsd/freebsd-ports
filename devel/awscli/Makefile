# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	awscli
PORTVERSION=	1.12.1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	Universal Command Line Interface for Amazon Web Services

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.8.1:devel/py-botocore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:devel/py-colorama@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3transfer>=0.1.9:net/py-s3transfer@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.2:security/py-rsa@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils concurrent
NO_ARCH=	yes

.include <bsd.port.mk>
