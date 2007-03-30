# New ports collection makefile for:    py-sqlite3
# Date created:         23 June 2006
# Whom:                 Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Standard Python binding to the SQLite3 library

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/_sqlite3.so
DIST_SUBDIR=	python
USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python/distinfo

pre-extract:
	@${CAT} ${PKGMESSAGE}

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
