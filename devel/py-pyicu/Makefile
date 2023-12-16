PORTNAME=	pyicu
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyICU-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python extension wrapping the ICU C++ API
WWW=		https://gitlab.pyicu.org/main/pyicu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicudata.so:devel/icu

USES=		compiler:c++11-lang pkgconfig python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
