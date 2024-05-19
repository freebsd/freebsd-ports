PORTNAME=	pyicu
PORTVERSION=	2.13
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyICU-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python extension wrapping the ICU C++ API
WWW=		https://gitlab.pyicu.org/main/pyicu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libicudata.so:devel/icu

USES=		compiler:c++11-lang pkgconfig python
USE_PYTHON=	autoplist concurrent pep517

WRKSRC=		${WRKDIR}/pyicu-${PORTVERSION}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
