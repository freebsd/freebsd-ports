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

ALL_TARGET=	MySQLmodule.so

pre-configure:
	${CP} ${FILESDIR}/Setup ${WRKSRC}/Setup
	${LN} -s ${LOCALBASE}/lib/python1.5/config/Makefile.pre.in ${WRKSRC}/

do-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/py-MySQL
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/py-MySQL
	@${ECHO} "share/doc/py-MySQL/README" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/py-MySQL" >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
