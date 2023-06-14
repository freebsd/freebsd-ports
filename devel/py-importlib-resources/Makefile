PORTNAME=	importlib-resources
PORTVERSION=	5.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	importlib_resources-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Read resources from Python packages
WWW=		https://github.com/python/importlib_resources

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.1:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zipp>=3.1.0:devel/py-zipp@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
