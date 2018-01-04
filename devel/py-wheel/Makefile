# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wheel
PORTVERSION=	0.30.0
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Built-package format for Python

LICENSE=	MIT

OPTIONS_DEFINE=	PIP SIGNATURE

PIP_DESC=	Use pip to install wheels
PIP_RUN_DEPENDS=	pip:devel/py-pip

SIGNATURE_DESC=	Enable digital signature of wheels
SIGNATURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirspec>=13.05:devel/py-dirspec@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ed25519ll>=0.6_1:security/py-ed25519ll@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}keyring>=1.3:security/py-keyring@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
