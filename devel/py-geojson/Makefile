PORTNAME=	geojson
PORTVERSION=	3.1.0
PORTEPOCH=	1
CATEGORIES=	devel geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python's Encoder/decoder for simple GIS features
WWW=		https://pypi.org/project/geojson/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.0:devel/py-nose@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>1.9:devel/py-simplejson@${PY_FLAVOR}

PORTDOCS=	LICENSE.rst CHANGELOG.rst README.rst

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
