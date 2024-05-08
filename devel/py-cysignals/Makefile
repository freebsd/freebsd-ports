PORTNAME=	cysignals
PORTVERSION=	1.11.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interrupt and signal handling for Cython
WWW=		https://pypi.org/project/cysignals/

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR}
LIB_DEPENDS=	libpari.so:math/pari
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	sagemath

USES=		compiler:c++11-lang gettext localbase python
USE_PYTHON=	cython distutils
BINARY_ALIAS=	python3=${PYTHON_CMD}

TEST_TARGET=	check

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		gmake
PORTDOCS=		*

pre-configure-DOCS-on:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|'	\
		${WRKSRC}/docs/Makefile

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/build/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
