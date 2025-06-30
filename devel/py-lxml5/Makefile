PORTNAME=	lxml
PORTVERSION=	5.4.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/lxml/lxml/releases/download/lxml-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pythonic XML processing library combining libxml2/libxslt
WWW=		https://lxml.de/ \
		https://github.com/lxml/lxml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe gnome python
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist concurrent cython3 pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}lxml ${PYTHON_PKGNAMEPREFIX}lxml5

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
