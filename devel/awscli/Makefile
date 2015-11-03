# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	awscli
PORTVERSION=	1.8.13
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Universal Command Line Interface for Amazon Web Services

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.2.11:${PORTSDIR}/devel/py-botocore \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:${PORTSDIR}/devel/py-colorama \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.2:${PORTSDIR}/security/py-rsa

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 2700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse
.endif

.include <bsd.port.post.mk>
