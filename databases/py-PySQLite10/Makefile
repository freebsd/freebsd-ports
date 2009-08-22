# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	PySQLite
PORTVERSION=	1.0.1
CATEGORIES=	databases python
MASTER_SITES=	SF/${PORTNAME:L}/OldFiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A DB-API v2 Python library for the SQLite 2 embedded SQL engine

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2

NO_LATEST_LINK=	yes

CONFLICTS=	py*-PySQLite-1.1.*

WRKSRC=		${WRKDIR}/pysqlite
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pysqlite

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

.include <bsd.port.mk>
