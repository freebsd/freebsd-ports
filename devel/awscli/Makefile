# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	awscli
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/a/awscli

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Universal Command Line Interface for Amazon Web Services

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=0.5.0:${PORTSDIR}/devel/py-botocore \
		${PYTHON_PKGNAMEPREFIX}six>=1.1.0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}tox>=1.4:${PORTSDIR}/devel/py-tox

USE_PYTHON=	2.6+
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
