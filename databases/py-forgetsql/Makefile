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

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	forgetSQL

DOCS=	BUGS README TODO

OPTIONS_DEFINE=	DOCS MYSQL PGSQL

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
PGSQL_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg

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
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
