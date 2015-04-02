# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyro
PORTVERSION=	4.35
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyro4-${PORTVERSION}.src

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Distributed Object Middleware for Python(IPC/RPC)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}serpent>=1.9:${PORTSDIR}/devel/py-serpent

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	*
PORTEXAMPLES=	*
WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
