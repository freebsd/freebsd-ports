# New ports collection makefile for:    py-bsddb
# Date created:         31 July 2003
# Whom:                 Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsddb
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python bindings to the Berkeley DB library

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
BROKEN=         "WITH_BDB_VER must be 3, 4, 41 or 42"
.endif
.endif

DIST_SUBDIR=	python
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python/distinfo
MAKE_ENV=	BSDDB_VERSION=${DBVERSION}

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		's,^\(#include.*\)\(db\.h.*\)$$,\1${DBHEADER}/\2,' \
		${WRKSRC}/_bsddb.c

.include <bsd.port.mk>
