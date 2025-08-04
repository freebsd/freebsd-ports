PORTNAME=	lxml
DISTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries
WWW=		https://lxml.de/ \
		https://github.com/lxml/lxml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/licenses/BSD.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		compiler cpe gnome python
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist concurrent cython3 pep517

LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib

DOCS_FILES=	CHANGES.txt CREDITS.txt TODO.txt README.rst
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# force regeneration of cython files
post-extract:
	@${FIND} ${WRKSRC} -name "*.c" -delete

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

# see upstream Makefile, test target
# tests require compiled extensions in the source directories
do-test:
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} build_ext --inplace && \
		${PYTHON_CMD} test.py -p -v

.include <bsd.port.pre.mk>

# if using gcc, force modern GCC due to use of #pragma
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
