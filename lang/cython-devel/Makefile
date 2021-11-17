PORTNAME=	cython
DISTVERSION=	3.0.0a9
CATEGORIES=	lang python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 python:2.7+
USE_PYTHON=	allflavors autoplist concurrent distutils
USE_GITHUB=	yes
GH_TAGNAME=	2b1e743

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
