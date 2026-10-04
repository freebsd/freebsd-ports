PORTNAME=	setupmeta
PORTVERSION=	3.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Simplify your setup.py
WWW=		https://github.com/codrsquad/setupmeta

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# setuptools>=67 floor is metadata only; code works with 63.1.0
post-patch:
	@${REINPLACE_CMD} '/setuptools>=67/d' ${WRKSRC}/setup.py \
		${WRKSRC}/PKG-INFO ${WRKSRC}/setupmeta.egg-info/requires.txt

.include <bsd.port.mk>
