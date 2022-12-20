PORTNAME=	pyglet
PORTVERSION=	2.0.2
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library
WWW=		https://pypi.org/project/pyglet/ \
		https://github.com/pyglet/pyglet

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		display:test gl python:3.6+ zip
USE_GL=		gl glu
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

CONFLICTS_INSTALL=${PYTHON_PKGNAMEPREFIX}${PORTNAME}1

.include <bsd.port.mk>
