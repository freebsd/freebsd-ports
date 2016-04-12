# $FreeBSD$

PORTNAME=	watchdog
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python API library to monitor file system events

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}argh>=0.24.1:devel/py-argh \
		${PKGNAMEPREFIX}pathtools>=0.1.2:devel/py-pathtools \
		${PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml

DOCS_BUILD_DEPENDS=	${PKGNAMEPREFIX}pathtools>=0.1.2:devel/py-pathtools \
		${PKGNAMEPREFIX}sphinx>=1.1.3:textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

GH_ACCOUNT=	gorakhargosh

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

USE_GITHUB=	yes
USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-build-DOCS-on:
	(cd ${WRKSRC}/docs ; ${MAKE_CMD} html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build/html ; \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

.include <bsd.port.mk>
