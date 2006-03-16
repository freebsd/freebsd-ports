# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MySQLdb
DISTVERSION=	1.2.1c7
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	MySQL-python-${DISTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		2.3+
USE_PYDISTUTILS=	yes
USE_MYSQL=		yes

CONFLICTS=	py*-MySQLdb-[0-9]*

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
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/MySQLdb.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
