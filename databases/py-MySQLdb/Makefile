# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MySQLdb
PORTVERSION=	1.2.0
PORTREVISION=	1
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
	@${ECHO} "	WITHOUT_MYSQLCLIENT_R=yes	Don't use mysqlclient_r lib"
	@${ECHO} "					but is not guarantee thread-safe."
	@${ECHO} ""
	@${ECHO} "	Default use mysqlclient_r"
	@${ECHO} ""

.if defined(WITHOUT_MYSQLCLIENT_R)
MAKE_ENV+=	mysqlclient="mysqlclient"
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.css ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/doc
	@${INSTALL_DATA} ${WRKSRC}/doc/doc/*.html ${DOCSDIR}/doc
	@${INSTALL_DATA} ${WRKSRC}/doc/doc/*.css ${DOCSDIR}/doc
	@${MKDIR} ${DOCSDIR}/doc/public
	@${INSTALL_DATA} ${WRKSRC}/doc/doc/public/* ${DOCSDIR}/doc/public
	@${MKDIR} ${DOCSDIR}/doc/private
	@${INSTALL_DATA} ${WRKSRC}/doc/doc/private/* ${DOCSDIR}/doc/private
	@${MKDIR} ${DOCSDIR}/public
	@${INSTALL_DATA} ${WRKSRC}/doc/public/* ${DOCSDIR}/public
	@${MKDIR} ${DOCSDIR}/private
	@${INSTALL_DATA} ${WRKSRC}/doc/private/* ${DOCSDIR}/private
.endif

.include <bsd.port.mk>
