# New ports collection makefile for:    py-bsddb
# Date created:         31 July 2003
# Whom:                 Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsddb
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYTHON}
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python bindings to the Berkeley DB library

.if defined(WITH_DB3)
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
DBVERSION=	db3     
PKGNAMESUFFIX=	-db3
.else
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
DBVERSION=	db4     
.endif

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python/distinfo
MAKE_ENV=	BSDDB_VERSION=${DBVERSION}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 230
IGNORE=		"is a port for python2.3 and later versions"
.endif

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		's,^\(#include.*\)\(db\.h.*\)$$,\1${DBVERSION}/\2,' \
		${WRKSRC}/_bsddb.c

.include <bsd.port.post.mk>
