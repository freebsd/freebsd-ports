# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-MySQLdb
PORTVERSION=	0.3.5
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
DISTNAME=	MySQL-python-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

DOCS=		README.MySQLmodule MANIFEST README


do-configure:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-MySQLdb/examples
.for file in ${DOCS}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/py-MySQLdb
.endfor
	@${INSTALL_MAN} \
		${WRKSRC}/examples/* ${PREFIX}/share/doc/py-MySQLdb/examples
.endif

.include <bsd.port.mk>
