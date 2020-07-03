# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyglet
PORTVERSION=	1.5.7
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=${PYTHON_PKGNAMEPREFIX}pyglet150-*

USES=		python:3.5+ zip
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
