# New ports collection makefile for:	py-bsddb3
# Date created:				22 March 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	bsddb3
PORTVERSION=	4.2.4
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pybsddb
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python extension module for BerkeleyDB 3 and 4

.if defined(WITH_DB3)
WITH_BDB_VER?=	3
.elif defined(WITH_DB4)
WITH_BDB_VER?=	4
.else
WITH_BDB_VER?=	41
.endif

.if defined(WITH_BDB_VER)
.if ${WITH_BDB_VER} == 3
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
DBVERSION=	db3
DBHEADER=	db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
DBVERSION=	db4
DBHEADER=	db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
DBVERSION=	db41
DBHEADER=	db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42
DBVERSION=	db-4.2
DBHEADER=	db42
.else
IGNORE=		"WITH_BDB_VER must be 3, 4, 41 or 42"
.endif
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
PYDISTUTILS_CONFIGUREARGS=--libs="-l${DBVERSION}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_BUILDARGS=	--libs="-l${DBVERSION}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} --berkeley-db=${LOCALBASE}

post-patch:
	${REINPLACE_CMD} 's,%%DBVERSION%%,${DBVERSION},g' ${WRKSRC}/setup.py
	${REINPLACE_CMD} 's,<db\.h>,<${DBHEADER}/db.h>,' ${WRKSRC}/extsrc/_bsddb.c

.include <bsd.port.mk>
