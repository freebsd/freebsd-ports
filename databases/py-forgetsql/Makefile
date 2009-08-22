# Ports collection makefile for:	py-forgetsql
# Date created:				20 November 2004
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	forgetsql
PORTVERSION=	0.5.1
CATEGORIES=	databases python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	forgetSQL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for object-oriented access to SQL databases

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif
.if defined(WITH_MYSQL)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	forgetSQL

DOCS=	BUGS README TODO

post-build:
	@cd ${WRKSRC}/lib && ${PYTHON_CMD} -c 'import forgetSQL'
	@cd ${WRKSRC}/lib && ${PYTHON_CMD} -O -c 'import forgetSQL'

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/forgetSQL.pyc ${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/forgetSQL.pyo ${PYTHON_SITELIBDIR}/
.if !defined(WITH_POSTGRESQL) && !defined(WITH_MYSQL)
	@${ECHO}
	@${ECHO_MSG} "===> You did not set WITH_MYSQL or WITH_POSTGRESQL. To make this port usable,"
	@${ECHO_MSG} "===> you should install py-psycopg or py-MySQLdb from ports/databases."
	@${ECHO}
.endif
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
