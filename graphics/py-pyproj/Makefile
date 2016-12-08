# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	pyproj
PORTVERSION=	1.9.5.1
CATEGORIES=	graphics python geography
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cython wrapper to provide python interfaces to PROJ.4 functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libproj.so:graphics/proj

USES=		python
USE_PYTHON=	distutils autoplist concurrent

MAKE_ENV=	PROJ_DIR=${LOCALBASE}

PORTDOCS=	*
PORTDOCS1=	Changelog README.md docs/*
PORTEXAMPLES=	datum_shift.py geodtest.py sample.out \
		test.py test2.py test_datum.py test_transform.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_proj.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS1:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/test/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
