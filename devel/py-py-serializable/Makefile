PORTNAME=	py-serializable
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/madpah/serializable/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_serializable-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for serializing and deserializing Python Objects to and from JSON and XML
WWW=		https://py-serializable.readthedocs.io/en/latest/ \
		https://github.com/madpah/serializable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1<0.8:devel/py-defusedxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
