# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	geojson
PORTVERSION=	1.0.6
PORTEPOCH=	1
CATEGORIES=	devel geography python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python's Encoder/decoder for simple GIS features

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.0:${PORTSDIR}/devel/py-nose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>1.9:${PORTSDIR}/devel/py-simplejson

DOCSFILE=	LICENSE.rst CHANGELOG.rst README.rst

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCSFILE}
	@cd ${WRKSRC} && ${CP} ${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
