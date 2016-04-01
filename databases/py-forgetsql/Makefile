# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forgetsql
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	forgetSQL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for object-oriented access to SQL databases

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	BUGS README TODO

OPTIONS_DEFINE=	DOCS MYSQL PGSQL

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb
PGSQL_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/psycopgmodule.so:databases/py-psycopg

.include <bsd.port.options.mk>

post-build:
	@cd ${WRKSRC}/lib && ${PYTHON_CMD} -c 'import forgetSQL'
	@cd ${WRKSRC}/lib && ${PYTHON_CMD} -O -c 'import forgetSQL'

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/forgetSQL.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/forgetSQL.pyo ${STAGEDIR}${PYTHON_SITELIBDIR}/
.if !${PORT_OPTIONS:MPGSQL} && !${PORT_OPTIONS:MMYSQL}
	@${ECHO}
	@${ECHO_MSG} "===> You did not set MYSQL or PGSQL. To make this port usable,"
	@${ECHO_MSG} "===> you should install py-psycopg or py-MySQLdb from ports/databases."
	@${ECHO}
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
