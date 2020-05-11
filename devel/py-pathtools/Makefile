# $FreeBSD$

PORTNAME=	pathtools
PORTVERSION=	0.1.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	File system general utilities for Python

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist

DOCS_BUILD_DEPENDS=	${PY_SPHINX}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	*

post-build:
	@(cd ${WRKSRC}/docs ; ${MAKE} SPHINXBUILD=sphinx-build-${PYTHON_VER} html)

post-install:
	@(cd ${WRKSRC}/docs/build/html ; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
