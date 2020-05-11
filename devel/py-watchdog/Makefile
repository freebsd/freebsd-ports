# $FreeBSD$

PORTNAME=	watchdog
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python API library to monitor file system events

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argh>=0.26.1:devel/py-argh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathtools>=0.1.2:devel/py-pathtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pathtools>=0.1.2:devel/py-pathtools@${PY_FLAVOR} \
		${PY_SPHINX}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

GH_ACCOUNT=	gorakhargosh

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-build-DOCS-on:
	(cd ${WRKSRC}/docs ; ${MAKE_CMD} SPHINXBUILD=sphinx-build-${PYTHON_VER} html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build/html ; \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

.include <bsd.port.mk>
