PORTNAME=	breathe
PORTVERSION=	4.33.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Extension to reStructuredText and Sphinx to render Doxygen xml output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
		doxygen:devel/doxygen

USES=		gmake python:3.7+
USE_GITHUB=	yes
GH_TUPLE=	michaeljones:breathe:v${PORTVERSION}
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

BINARY_ALIAS=	sphinx-build=sphinx-build-${PYTHON_VER}

OPTIONS_DEFINE=		DOCS EXAMPLES PDFDOCS
OPTIONS_SUB=		yes
PDFDOCS_DESC=		Build PDF documentation (implies DOCS)
PDFDOCS_IMPLIES=	DOCS
PDFDOCS_BUILD_DEPENDS=	pdflatex:print/tex-formats

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
		${REINPLACE_CMD} "s/^git_tag = subprocess.*/git_tag = b'v${PORTVERSION}'/" \
			${WRKSRC}/documentation/source/conf.py

post-build-DOCS-on:
		cd ${WRKSRC} && \
			${SETENV} PYTHONPATH=${WRKSRC}/ \
				${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
				${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS:N${DESTDIRNAME}=*} html </dev/null

post-build-PDFDOCS-on:
		cd ${WRKSRC} && \
			${SETENV} PYTHONPATH=${WRKSRC}/ \
				${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
				${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS:N${DESTDIRNAME}=*} pdf </dev/null

post-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		cd ${WRKSRC}/documentation/build && \
			${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} && \
			${RM} -r ${STAGEDIR}${DOCSDIR}/html/_sources

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC}/examples && \
			${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-PDFDOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/documentation/build/latex/*.pdf ${STAGEDIR}${DOCSDIR}

do-test:
		cd ${WRKSRC}/tests && \
			PYTHONPATH=../:${STAGEDIR}${PYTHON_SITELIBDIR} \
			${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>
