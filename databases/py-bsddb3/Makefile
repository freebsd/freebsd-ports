# New ports collection makefile for:	py-bsddb3
# Date created:				22 March 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	bsddb3
PORTVERSION=	4.1.6
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pybsddb
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python extension module for BerkeleyDB 3 and 4

.if defined(WITH_DB3)
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
DBVERSION=	db3
PKGNAMESUFFIX=	-db3
.else
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
DBVERSION=	db4
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
PYDISTUTILS_BUILDARGS=	--libs="-l${DBVERSION}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} --berkeley-db=${LOCALBASE}

post-patch:
	${REINPLACE_CMD} 's,%%DBVERSION%%,${DBVERSION},g' ${WRKSRC}/setup.py
	${REINPLACE_CMD} 's,<db\.h>,<${DBVERSION}/db.h>,' ${WRKSRC}/extsrc/_bsddb.c

.include <bsd.port.mk>
