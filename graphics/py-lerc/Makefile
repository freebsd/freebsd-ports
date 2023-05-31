PORTNAME=	lerc
PORTVERSION=	4.0.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for LERC (Limited Error Raster Compression)
WWW=		https://esri.github.io/lerc/ \
		https://github.com/Esri/lerc/tree/master/OtherLanguages/Python

LICENSE=	APACHE20

LIB_DEPENDS=	libLerc.so:graphics/lerc

USES=		dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${RM} ${WRKSRC}/lerc/libLerc.so.4

# lib/libLerc.* are not available until configure phase
post-configure:
	@${CP} ${LOCALBASE}/lib/libLerc.so.* ${WRKSRC}/lerc/

.include <bsd.port.mk>
