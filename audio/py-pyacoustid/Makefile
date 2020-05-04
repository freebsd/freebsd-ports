# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyacoustid
PORTVERSION=	1.2.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings for Chromaprint acoustic fingerprinting and the Acoustid API

LICENSE=	MIT

LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}audioread>=0:audio/py-audioread@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
