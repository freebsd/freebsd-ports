PORTNAME=	pyro
DISTVERSION=	4.77
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyro4-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Distributed Object Middleware for Python (IPC/RPC)
WWW=		https://pythonhosted.org/Pyro4/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream development stopped, not compatible with py311, use pyro5 instead
EXPIRATION_DATE=2025-03-21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}serpent>=1.27:devel/py-serpent@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	pyro_project
NO_ARCH=	yes
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/source && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
