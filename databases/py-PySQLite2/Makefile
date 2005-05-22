# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=		pysqlite
PORTVERSION=		2.0.0
CATEGORIES=		databases python
MASTER_SITES=		http://initd.org/pub/software/pysqlite/releases/2.0/2.0.0/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		A DB-API v2 Python library for the SQLite 3 embedded SQL engine

LIB_DEPENDS=		sqlite3.8:${PORTSDIR}/databases/sqlite3

LATEST_LINK=		${PYTHON_PKGNAMEPREFIX}${PORTNAME}2

USE_REINPLACE=		yes
USE_PYTHON=		2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib
DOCSBASE=		share/doc/py-${PORTNAME}2
DOCSDIR=		${PREFIX}/${DOCSBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=		*
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/setup.cfg
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|pysqlite2-doc|${DOCSBASE}|" ${WRKSRC}/setup.py
.else
	@${REINPLACE_CMD} -e "s|data_files = data_files,||" ${WRKSRC}/setup.py
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/code
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif

.include <bsd.port.mk>
