# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MySQLdb
PORTVERSION=	1.1.9
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	MySQL-python-${PORTVERSION}

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_MYSQL=		yes

CONFLICTS=	py*-MySQLdb-[0-9]*

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_MYSQLCLIENT_R=yes	Use mysqlclient_r lib"
	@${ECHO} ""

.if defined(WITH_MYSQLCLIENT_R)
MAKE_ENV+=	mysqlclient="mysqlclient_r"
.else
MAKE_ENV+=	mysqlclient="mysqlclient"
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.css
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/public
.for FILE in ${WRKSRC}/doc/public/*
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/public
.endfor
	@${MKDIR} ${DOCSDIR}/private
.for FILE in ${WRKSRC}/doc/private/*
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/private
.endfor
.endif

.include <bsd.port.mk>
