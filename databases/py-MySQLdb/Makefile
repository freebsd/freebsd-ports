# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MySQLdb
PORTVERSION=	1.0.1
PORTREVISION=	0
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MySQL-python-${PORTVERSION}

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_MYSQL=		yes

CONFLICTS=	py*-MySQLdb-devel-[0-9]*

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_MYSQLCLIENT_R=yes	Use mysqlclient_r lib"
	@${ECHO} "	WITH_MYSQLSSL=yes	Use SSL support"
	@${ECHO} "	WITH_MYSQLCRYPTO=yes	Use CRYPTO support"
	@${ECHO} ""

.if defined(WITH_MYSQLCLIENT_R)
MAKE_ENV+=	mysqlclient="mysqlclient_r"
.else
MAKE_ENV+=	mysqlclient="mysqlclient"
.endif

.if defined(WITH_MYSQLSSL)
.if defined(WITH_MYSQLCRYPTO)
MAKE_ENV+=	mysqloptlibs="ssl crypto"
.else
MAKE_ENV+=	mysqloptlibs="ssl"
.endif
.else
.if defined(WITH_MYSQLCRYPTO)
MAKE_ENV+=	mysqloptlibs="crypto"
.else
MAKE_ENV+=	mysqloptlibs=""
.endif
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/MANIFEST ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for FILE in ${WRKSRC}/doc/*
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
