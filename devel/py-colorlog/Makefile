# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colorlog
PORTVERSION=	3.1.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python module for log formatting with colors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
