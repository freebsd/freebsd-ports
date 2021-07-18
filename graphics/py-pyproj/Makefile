# Created by: TAOKA Fumiyoshi

PORTNAME=	pyproj
PORTVERSION=	3.1.0
CATEGORIES=	graphics geography python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cython wrapper to provide python interfaces to PROJ.4 functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	proj>=7.2.0,1:graphics/proj
LIB_DEPENDS=	libproj.so:graphics/proj

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

MAKE_ENV=	PROJ_DIR=${LOCALBASE}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyproj/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/sample.out ${WRKSRC}/test/test_*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
