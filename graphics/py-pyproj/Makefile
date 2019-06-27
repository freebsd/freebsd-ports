# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	pyproj
PORTVERSION=	2.1.3
CATEGORIES=	graphics python geography
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cython wrapper to provide python interfaces to PROJ.4 functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libproj.so:graphics/proj

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

MAKE_ENV=	PROJ_DIR=${LOCALBASE}

PORTDOCS=	*
PORTDOCS1=	README.md docs/*
PORTEXAMPLES=	sample.out \
		test.py test_awips221.py test_crs.py test_datadir.py \
		test_datum.py test_datum_shift.py test_doctest_wrapper.py \
		test_exception_logging.py test_geod.py test_pickle.py \
		test_transform.py test_transformer.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_proj.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR} "! -name .buildinfo" )

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/test/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
