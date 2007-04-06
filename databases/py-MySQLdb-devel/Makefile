# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MySQLdb
DISTVERSION=	1.2.2b2
PORTREVISION=	1
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

PORTDOCS=	*
BROKEN=		Latest version are in databases/py-MySQLdb

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS=	MYSQLCLIENT_R "Use libmysqlclient_r (thread safe)" on

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITHOUT_MYSQLCLIENT_R)
	@${REINPLACE_CMD} -E -e "s|(threadsafe.*)True|\1 False|" \
		${WRKSRC}/site.cfg
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
