# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	lupa
PORTVERSION=	1.12
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper around Lua and LuaJIT

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		lua pkgconfig python:3.6+
USE_PYTHON=	autoplist concurrent distutils

MAKE_ARGS=	--no-bundle

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third-party/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
