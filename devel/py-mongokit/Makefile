# Created by: Mirko Zinn <mail@derzinn.de>
# $FreeBSD$

PORTNAME=		mongokit
PORTVERSION=		0.9.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=		devel python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@derzinn.de
COMMENT=	Python ORM-like layer on top of pymongo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=2.5:databases/pymongo@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	namlook

NO_ARCH=	yes
PORTDOCS=	*.txt

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	# Remove introduction.txt, soft-link causes issue
	${RM} ${WRKSRC}/doc/introduction.txt
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
