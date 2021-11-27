# Created by: bland@FreeBSD.org

PORTNAME=	xattr
PORTVERSION=	0.9.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Python wrapper for extended filesystem attributes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/xattr/_lib*.so

.include <bsd.port.mk>
