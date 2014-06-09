# Created by: Po-Chien Lin <linpc@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jsmin
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	JavaScript minifier written in Python

LICENSE=	MIT

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	PKG-INFO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

regression-test:
	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>
