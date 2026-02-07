PORTNAME=	pyglet
PORTVERSION=	1.5.31
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library (legacy version)
WWW=		https://pypi.org/project/pyglet/ \
		https://github.com/pyglet/pyglet

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		display:test gl python zip
USE_GL=		gl glu
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

CONFLICTS_INSTALL=${PYTHON_PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
