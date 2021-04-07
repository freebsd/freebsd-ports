PORTNAME=	mysqlclient
DISTVERSION=	2.0.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	MySQL database connector for Python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 iconv mysql python:3.6+ ssl
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	*

CONFLICTS=	py*-MySQLdb-[0-9]* py*-MySQLdb5[0-9]-[0-9]* py*-MySQLdb

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
