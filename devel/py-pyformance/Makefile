# Created by: Waitman Gobble <waitman@waitman.net>
# $FreeBSD$

PORTNAME=	pyformance
PORTVERSION=	0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	PyFormance is a toolset for performance measurement and statistics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
