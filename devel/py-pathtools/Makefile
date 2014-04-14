# $FreeBSD$

PORTNAME=	pathtools
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	File system general utilities for Python

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

PYDISTUTILS_AUTOPLIST=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-build:
	@(cd ${WRKSRC}/docs ; ${MAKE} html)

post-install:
	@(cd ${WRKSRC}/docs/build/html ; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv")
.endif

.include <bsd.port.mk>
