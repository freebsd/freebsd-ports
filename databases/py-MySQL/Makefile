# New ports collection makefile for:	py-MySQL
# Date created:				05 September 1999
# Whom:                 		Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	py-MySQL
PORTVERSION=	1.4
CATEGORIES=	databases python
MASTER_SITES=	http://www.mysql.com/Contrib/
DISTNAME=	MySQLmodule-${PORTVERSION}

MAINTAINER=	dr@domix.de

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/MySQLmodule.so ${PREFIX}/lib/python1.5/site-packages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/py-MySQL
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/py-MySQL
.endif

post-install:
.if !defined(NOPORTDOCS)
	${ECHO} "share/doc/py-MySQL/README" >> ${TMPPLIST}
	${ECHO} "@dirrm share/doc/py-MySQL" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
