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

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} != "python2.1" && ${PYTHON_VERSION} != "python2.2"
ALL_TARGET=	MySQLmodule.so
.endif
.if ${PYTHON_VERSION} == "python2.2"
MAKEFILE_PREIN=	${FILESDIR}/Makefile.pre.in
.else
MAKEFILE_PREIN=	${LOCALBASE}/lib/${PYTHON_VERSION}/config/Makefile.pre.in
.endif

pre-configure:
	${CP} ${FILESDIR}/Setup ${WRKSRC}/Setup
	${LN} -s ${MAKEFILE_PREIN} ${WRKSRC}/

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

.include <bsd.port.post.mk>
