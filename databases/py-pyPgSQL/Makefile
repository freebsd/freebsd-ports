# New ports collection makefile for:   py-pypgsql
# Date created:                        01 Nov 2001
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pyPgSQL
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pypgsql
PKGNAMEPREFIX=	py-
DISTNAME=	pyPgSQL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python DB-API 2 compliant library for using PostgreSQL databases

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base

WRKSRC=		${WRKDIR}/pypgsql

USE_PGSQL=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		README README.html
EXAMPLES=	examples/*.py

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

DOCSDIR=	${PREFIX}/share/doc/py-pyPgSQL
EXAMPLESDIR=	${PREFIX}/share/examples/py-pyPgSQL

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
