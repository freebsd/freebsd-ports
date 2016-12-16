# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	awscli
PORTVERSION=	1.11.29
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP

MAINTAINER=	bradleythughes@fastmail.fm
COMMENT=	Universal Command Line Interface for Amazon Web Services

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.4.86:devel/py-botocore \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:devel/py-colorama \
		${PYTHON_PKGNAMEPREFIX}s3transfer>=0.1.9:net/py-s3transfer \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.2:security/py-rsa \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
