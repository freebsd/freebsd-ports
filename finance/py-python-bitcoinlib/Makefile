# $FreeBSD$

PORTNAME=	python-bitcoinlib
PORTVERSION=	0.11.0
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Swiss Army Knife of the Bitcoin protocol

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
