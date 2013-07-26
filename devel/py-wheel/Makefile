# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wheel
PORTVERSION=	0.21.0
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Built-package format for Python

LICENSE=	MIT

USE_PYDISTUTILS=	easy_install
# Python 3 ready
USE_PYTHON=	yes

OPTIONS_DEFINE=	PIP SIGNATURE
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
PIP_DESC=	Use pip to install wheels
SIGNATURE_DESC=	Enable digital signature of wheels

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPIP}
RUN_DEPENDS+=	pip:${PORTSDIR}/devel/py-pip
.endif

.if ${PORT_OPTIONS:MSIGNATURE}
.	if ${PYTHON_REL} < 270
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>=1.1:${PORTSDIR}/devel/py-argparse
.	endif
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dirspec>=13.05:${PORTSDIR}/devel/py-dirspec \
		${PYTHON_PKGNAMEPREFIX}keyring>=1.3:${PORTSDIR}/security/py-keyring
.endif

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
