# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-MySQLdb
PORTVERSION=	0.2.2
CATEGORIES=	databases python
MASTER_SITES=	http://dustman.net/andy/python/MySQLdb/${PORTVERSION}/
DISTNAME=	MySQLdb-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client

USE_PYTHON=	yes
ALL_TARGET=	_mysqlmodule.o

pre-configure:
	@${LN} -s ${LOCALBASE}/lib/${PYTHON_VERSION}/config/Makefile.pre.in ${WRKSRC}/

do-configure:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

post-build:
	@-${LOCALBASE}/bin/python \
		${LOCALBASE}/lib/${PYTHON_VERSION}/compileall.py ${WRKSRC} 2>/dev/null

post-install:
	@${INSTALL_DATA} \
		${WRKSRC}/MySQLdb.pyc ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-MySQLdb/examples
	@${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/py-MySQLdb
	@${INSTALL_MAN} \
		${WRKSRC}/examples/* ${PREFIX}/share/doc/py-MySQLdb/examples
.endif

.include <bsd.port.mk>
