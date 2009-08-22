# New ports collection makefile for:   py-pypgsql
# Date created:                        01 Nov 2001
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pyPgSQL
PORTVERSION=	2.5.1
PORTREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A Python DB-API 2 compliant library for using PostgreSQL databases

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base

USE_PGSQL=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		Announce ChangeLog README README.html
EXAMPLES=	examples/*.py

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

DOCSDIR=	${PREFIX}/share/doc/py-pyPgSQL
EXAMPLESDIR=	${PREFIX}/share/examples/py-pyPgSQL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
