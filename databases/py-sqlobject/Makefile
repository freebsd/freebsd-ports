# Ports collection makefile for:	py-sqlobject
# Date created:				24 June 2004
# Whom:					"Choe, Cheng-Dae" whitekid
#
# $FreeBSD$
#

PORTNAME=	sqlobject
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/S/SQLObject/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	A python object for manipulation with SQL table row

# Someone will add SQLite, Firebird and DBMConnection support things.
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/formencode/__init__.py:${PORTSDIR}/www/py-formencode \
		${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb \
		${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
