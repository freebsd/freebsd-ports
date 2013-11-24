# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	awscli
PORTVERSION=	1.2.5
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/a/awscli

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Universal Command Line Interface for Amazon Web Services

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcdoc>=0.11.0:${PORTSDIR}/devel/py-bcdoc \
		${PYTHON_PKGNAMEPREFIX}botocore>=0.25:${PORTSDIR}/devel/py-botocore \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:${PORTSDIR}/devel/py-colorama \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.2:${PORTSDIR}/security/py-rsa \
		${PYTHON_PKGNAMEPREFIX}six>=1.1.0:${PORTSDIR}/devel/py-six

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 270
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse
.endif

.include <bsd.port.post.mk>
