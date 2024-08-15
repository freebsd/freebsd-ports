PORTNAME=	pyglet
PORTVERSION=	2.0.17
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library
WWW=		https://pypi.org/project/pyglet/ \
		https://github.com/pyglet/pyglet

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

USES=		display:test gl python
USE_GL=		gl glu
USE_PYTHON=	autoplist pep517 pytest
NO_ARCH=	yes

CONFLICTS_INSTALL=${PYTHON_PKGNAMEPREFIX}${PORTNAME}1

.include <bsd.port.mk>
