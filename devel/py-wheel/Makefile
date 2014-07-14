# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wheel
PORTVERSION=	0.24.0
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Built-package format for Python

LICENSE=	MIT

OPTIONS_DEFINE=	PIP SIGNATURE
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PIP_DESC=	Use pip to install wheels
PIP_RUN_DEPENDS=	pip:${PORTSDIR}/devel/py-pip
PYDISTUTILS_AUTOPLIST=	yes

SIGNATURE_DESC=	Enable digital signature of wheels
SIGNATURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirspec>=13.05:${PORTSDIR}/devel/py-dirspec \
			${PYTHON_PKGNAMEPREFIX}keyring>=1.3:${PORTSDIR}/security/py-keyring \
			${PYTHON_PKGNAMEPREFIX}xdg>=0.25:${PORTSDIR}/devel/py-xdg

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
