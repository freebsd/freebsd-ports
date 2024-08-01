PORTNAME=	mysqlclient
DISTVERSION=	2.2.4
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	MySQL database connector for Python
WWW=		https://pypi.org/project/mysqlclient

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.37:devel/py-wheel@${PY_FLAVOR}

USES=		compiler:c11 dos2unix iconv mysql pkgconfig python ssl
USE_PYTHON=	autoplist concurrent pep517

PORTDOCS=	*

CONFLICTS=	py*-MySQLdb py*-MySQLdb5[0-9] py*-MySQLdb

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
