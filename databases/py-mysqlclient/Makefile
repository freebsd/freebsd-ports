# $FreeBSD$

PORTNAME=	mysqlclient
DISTVERSION=	1.4.6
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTVERSIONPREFIX=	v

MAINTAINER=	neel@neelc.org
COMMENT=	MySQL database connector for Python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 iconv mysql python ssl
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	pymysql
GH_PROJECT=	${PORTNAME}-python

CONFLICTS=	py*-MySQLdb-[0-9]* py*-MySQLdb5[0-9]-[0-9]* py*-MySQLdb

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
