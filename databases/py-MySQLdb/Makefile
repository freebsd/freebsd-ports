# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-MySQLdb
PORTVERSION=	0.3.0b1
CATEGORIES=	databases python
MASTER_SITES=	http://dustman.net/andy/python/MySQLdb/0.3.0/
DISTNAME=	MySQL-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client

WRKSRC=		${WRKDIR}/MySQLdb-${PORTVERSION}

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-configure:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-MySQLdb/examples
	@${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/py-MySQLdb
	@${INSTALL_MAN} \
		${WRKSRC}/examples/* ${PREFIX}/share/doc/py-MySQLdb/examples
.endif

.include <bsd.port.mk>
