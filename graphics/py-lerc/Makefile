PORTNAME=	lerc
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for LERC (Limited Error Raster Compression)
WWW=		https://esri.github.io/lerc/ \
		https://github.com/Esri/lerc/tree/master/OtherLanguages/Python

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libLerc.so:graphics/lerc

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

post-patch:
	@${RM} ${WRKSRC}/lerc/libLerc.so.4

# lib/libLerc.* are not available until configure phase
post-configure:
	@${CP} ${LOCALBASE}/lib/libLerc.so.* ${WRKSRC}/lerc/

.include <bsd.port.mk>
