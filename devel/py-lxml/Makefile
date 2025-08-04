PORTNAME=	lxml
PORTVERSION=	4.9.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries
WWW=		https://lxml.de/ \
		https://github.com/lxml/lxml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/licenses/BSD.txt

USES=		compiler cpe gnome python uniquefiles:dirs
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist concurrent cython distutils

LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib

DOCS_FILES=	CHANGES.txt CREDITS.txt TODO.txt README.rst
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# needed for test to work
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=		--inplace

# force regeneration of cython files
post-extract:
	@${FIND} ${WRKSRC} -name "*.c" -delete

pre-configure: # remove with update to 5.x
	@if ! xml2-config --version | ${GREP} -q ^2\.11; then \
		${REINPLACE_CMD} -e 's|, xmlerror.xmlError\*|, const xmlerror.xmlError*|' \
			${WRKSRC}/src/lxml/*.pxi; \
	fi

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

# see upstream Makefile, test target
do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test.py -p -v

.include <bsd.port.pre.mk>

# if using gcc, force modern GCC due to use of #pragma
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
