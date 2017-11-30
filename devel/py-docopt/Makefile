# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docopt
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Pythonic argument parser, that will make you smile

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README.rst
PORTEXAMPLES=	*

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
