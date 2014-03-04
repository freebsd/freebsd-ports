# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	bsddb3
PORTVERSION=	5.3.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python extension module for BerkeleyDB 3 and 4

USE_BDB=	43+
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PYDISTUTILS_CONFIGUREARGS=--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_BUILDARGS=	--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} --berkeley-db=${LOCALBASE}

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's,%%DBVERSION%%,${BDB_LIB_NAME},g' ${WRKSRC}/setup2.py ${WRKSRC}/setup3.py
	${REINPLACE_CMD} 's,<db\.h>,<${BDB_INCLUDE_DIR}/db.h>,' ${WRKSRC}/Modules/bsddb.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
