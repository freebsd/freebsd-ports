# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	geojson
PORTVERSION=	1.0.9
PORTEPOCH=	1
CATEGORIES=	devel geography python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python's Encoder/decoder for simple GIS features

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.0:${PORTSDIR}/devel/py-nose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>1.9:${PORTSDIR}/devel/py-simplejson

PORTDOCS=	LICENSE.rst CHANGELOG.rst README.rst

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
