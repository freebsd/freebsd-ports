# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-MySQLdb
PORTVERSION=	0.9.2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mysql-python
DISTNAME=	MySQL-python-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		MANIFEST README doc/*.html

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
