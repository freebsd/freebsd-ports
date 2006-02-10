# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	PySQLite
PORTVERSION=	1.1.7
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/${PORTVERSION:C/\.[0-9]$//}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A DB-API v2 Python library for the SQLite 3 embedded SQL engine

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

CONFLICTS=	py*-PySQLite-1.0*

NO_LATEST_LINK=	yes

WRKSRC=		${WRKDIR}/pysqlite
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	LOCALBASE="${LOCALBASE}"

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|"freebsd5",|"freebsd5", "freebsd6", "freebsd7",|' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rest/manual.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
.endif
# fix lib shared permission
	@${CHMOD} ${BINMODE} ${PYTHON_SITELIBDIR}/_sqlite.so

.include <bsd.port.mk>
