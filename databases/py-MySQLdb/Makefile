# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MySQLdb
DISTVERSION=	1.2.3
PORTREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	SF/mysql-python/mysql-python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MySQL-python-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_MYSQL=		yes

CONFLICTS=	py*-MySQLdb-[0-9]* py*-MySQLdb5[0-9]-[0-9]*

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=		DOCS MYSQLCLIENT_R
OPTIONS_DEFAULT=	DOCS MYSQLCLIENT_R
MYSQLCLIENT_R_DESC=	Use libmysqlclient_r (thread safe)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQLCLIENT_R}
pre-configure:
	@${REINPLACE_CMD} -E -e "s|(threadsafe.*)True|\1 False|" \
		${WRKSRC}/site.cfg
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
