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

USE_BDB=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python/distinfo
MAKE_ENV=	BSDDB_VERSION=${BDB_LIB_NAME}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_bsddb.so

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		's,^\(#include.*\)\(db\.h.*\)$$,\1${BDB_INCLUDE_DIR}/\2,' \
		${WRKSRC}/_bsddb.c

.include <bsd.port.mk>
