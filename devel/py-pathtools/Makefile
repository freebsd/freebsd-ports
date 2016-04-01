# $FreeBSD$

PORTNAME=	pathtools
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	File system general utilities for Python

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PKGNAMEPREFIX}sphinx>=1.1.3:textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-build:
	@(cd ${WRKSRC}/docs ; ${MAKE} html)

post-install:
	@(cd ${WRKSRC}/docs/build/html ; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv")
.endif

.include <bsd.port.mk>
