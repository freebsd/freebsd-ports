PORTNAME=	pyglet
PORTVERSION=	1.5.26
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		display:test gl python:3.6+ pytest zip
USE_GL=		gl glu
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
