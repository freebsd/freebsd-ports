PORTNAME=	breathe
PORTVERSION=	4.31.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	an extension to reStructuredText and Sphinx to render Doxygen xml output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=		${RUN_DEPENDS}
RUN_DEPENDS=		doxygen:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
PDFDOCS_BUILD_DEPENDS=	pdflatex:print/tex-formats

USES=		gmake python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	distutils
GH_TUPLE=	michaeljones:breathe:v${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES PDFDOCS
OPTIONS_SUB=	yes
PDFDOCS_DESC=	Build PDF documentation (implies DOCS)
PDFDOCS_IMPLIES=DOCS

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

post-install-PDFDOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/documentation/build/latex/*.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC}/examples && \
			${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
		cd ${WRKSRC}/tests && \
			PYTHONPATH=../:${STAGEDIR}${PYTHON_SITELIBDIR} \
			${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>
