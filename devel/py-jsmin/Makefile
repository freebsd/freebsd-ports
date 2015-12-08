# Created by: Po-Chien Lin <linpc@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jsmin
PORTVERSION=	2.1.6
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript minifier written in Python

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	PKG-INFO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test:
	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>
