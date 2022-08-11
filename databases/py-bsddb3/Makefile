PORTNAME=	bsddb3
PORTVERSION=	6.2.9
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python extension module for BerkeleyDB 4.7, 4.8, 5.1, 5.3, 6.1 and 6.2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Requires upstream EOLd db5. Use py-berkeleydb
EXPIRATION_DATE=	2022-06-30

USES=		bdb:5 python:3.6-3.9
USE_PYTHON=	autoplist distutils

PYDISTUTILS_CONFIGUREARGS=	--libs="-l${BDB_LIB_NAME}" \
				--berkeley-db=${LOCALBASE}
PYDISTUTILS_BUILDARGS=	--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
				--berkeley-db=${LOCALBASE}

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's,%%DBVERSION%%,${BDB_LIB_NAME},g' ${WRKSRC}/setup2.py ${WRKSRC}/setup3.py
	@${REINPLACE_CMD} 's,<db\.h>,<${BDB_INCLUDE_DIR}/db.h>,' ${WRKSRC}/Modules/bsddb.h
	@${REINPLACE_CMD} 's,%%BDB_INCLUDE_DIR%%,${BDB_INCLUDE_DIR},' ${WRKSRC}/setup2.py ${WRKSRC}/setup3.py
	@${REINPLACE_CMD} 's,%%BDB_LIB_NAME%%,${BDB_LIB_NAME},' ${WRKSRC}/setup3.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bsddb3/_pybsddb*.so

.include <bsd.port.mk>
