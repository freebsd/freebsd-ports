# Created by: Hye-Shik Chang <perky@python.or.kr>

PORTNAME=	berkeleydb
PORTVERSION=	18.1.5
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for Oracle Berkeley DB

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		bdb python:3.7+
USE_PYTHON=	distutils autoplist

PYDISTUTILS_CONFIGUREARGS=--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_BUILDARGS=	--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} --berkeley-db=${LOCALBASE}

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|%%DBVERSION%%|${BDB_LIB_NAME}| ; \
		s|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}| ; \
		s|%%BDB_LIB_NAME%%|${BDB_LIB_NAME}|' \
		${WRKSRC}/setup3.py
	@${REINPLACE_CMD} 's|<db\.h>|<${BDB_INCLUDE_DIR}/db.h>|' ${WRKSRC}/src/Module/berkeleydb.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_${PORTNAME}.cpython-*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./test.py

.include <bsd.port.mk>
