# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-MySQLdb
PORTVERSION=	1.1.7
PORTREVISION=	0
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
DISTNAME=	MySQL-python-${PORTVERSION}

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_MYSQL=		yes

CONFLICTS=	py-MySQLdb-0.* py-MySQLdb-1.[0,2-9].*

OPTIONS=	MYSQLCLIENT_R "Use mysqlclient_r lib" off \
		MYSQLSSL "Use SSL support" off \
		MYSQLCRYPTO "Use CRYPTO support" off

.include <bsd.port.pre.mk>

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

PORTDOCS=		MANIFEST README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
