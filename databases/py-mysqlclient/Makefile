PORTNAME=	mysqlclient
DISTVERSION=	2.1.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	MySQL database connector for Python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 iconv mysql python:3.7+ ssl
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	*

CONFLICTS=	py*-MySQLdb py*-MySQLdb5[0-9] py*-MySQLdb

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
