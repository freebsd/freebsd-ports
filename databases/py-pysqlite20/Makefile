# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=		PySQLite
PORTVERSION=		1.1.6
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysqlite
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		pysqlite-${PORTVERSION}

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		A DB-API v2 Python library for the SQLite 3 embedded SQL engine

LIB_DEPENDS=		sqlite3.8:${PORTSDIR}/databases/sqlite3

LATEST_LINK=		${PYTHON_PKGNAMEPREFIX}${PORTNAME}11

CONFLICTS=		py*-PySQLite-1.0*

WRKSRC=			${WRKDIR}/pysqlite
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=		*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rest/manual.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
