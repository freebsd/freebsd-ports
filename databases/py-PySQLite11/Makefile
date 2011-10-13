# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	PySQLite
PORTVERSION=	1.1.8
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/${PORTVERSION:C/\.[0-9]$//}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A DB-API v2 Python library for the SQLite 3 embedded SQL engine

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

CONFLICTS=	py*-PySQLite-1.0.*

DEPRECATED=	unmaintained upstream, only useful for python2.4 or less, no consumers in the ports tree
EXPIRATION_DATE=	2011-12-11

NO_LATEST_LINK=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pysqlite

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|"freebsd5",|"freebsd5", "freebsd6", "freebsd7",|' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
# fix lib shared permission
	@${CHMOD} ${BINMODE} ${PYTHON_SITELIBDIR}/_sqlite.so

.include <bsd.port.mk>
