# New ports collection makefile for:	py-bsddb3
# Date created:				22 March 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	bsddb3
PORTVERSION=	4.4.2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pybsddb
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python extension module for BerkeleyDB 3 and 4

USE_BDB=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_CONFIGUREARGS=--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_BUILDARGS=	--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} --berkeley-db=${LOCALBASE}

post-patch:
	${REINPLACE_CMD} 's,%%DBVERSION%%,${BDB_LIB_NAME},g' ${WRKSRC}/setup.py
	${REINPLACE_CMD} 's,<db\.h>,<${BDB_INCLUDE_DIR}/db.h>,' ${WRKSRC}/extsrc/_bsddb.c

.include <bsd.port.mk>
