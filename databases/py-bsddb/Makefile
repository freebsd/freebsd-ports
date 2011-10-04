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

MAINTAINER?=	python@FreeBSD.org
COMMENT=	Python bindings to the Berkeley DB library

USE_BDB=	yes
USE_PYTHON?=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	_bsddb
PYDISTUTILS_PKGVERSION=	0.0.0
DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}/Modules
DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
MAKE_ENV=	BSDDB_VERSION=${BDB_LIB_NAME}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_bsddb.so

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 300
IGNORE=	bsddb package was removed from core standard library since 3.0, use databases/py-bsddb3 instead
.endif

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.if ${PYTHON_REL} < 260
BSDDB_PATCH=	_bsddb.c
.else
BSDDB_PATCH=	bsddb.h
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's,^\(#include.*\)\(db\.h.*\)$$,\1${BDB_INCLUDE_DIR}/\2,' \
		${WRKSRC}/${BSDDB_PATCH}

.include <bsd.port.post.mk>
