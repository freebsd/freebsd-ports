# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-MySQLdb
PORTVERSION=	1.0.0
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
DISTNAME=	MySQL-python-${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_MYSQL=		yes

PORTDOCS=		MANIFEST README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
