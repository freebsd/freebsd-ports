# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	PySQLite
PORTVERSION=	0.4.3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysqlite
PKGNAMEPREFIX=	py-
DISTNAME=	pysqlite-${PORTVERSION}

MAINTAINER=	gh@ghaering.de
COMMENT=	A DB-API v2 Python library for the SQLite embedded SQL engine

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite

WRKSRC=		${WRKDIR}/pysqlite-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		README

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
