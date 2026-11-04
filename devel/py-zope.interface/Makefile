PORTNAME=	zope.interface
DISTVERSION=	5.3.0
PORTREVISION=	2
CATEGORIES=	devel python zope
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Interfaces for Python
WWW=		https://pypi.org/project/zope.interface/

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/zope/interface/_zope_interface_coptimizations*.so

.include <bsd.port.mk>
