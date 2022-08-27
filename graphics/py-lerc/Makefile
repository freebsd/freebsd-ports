PORTNAME=	lerc
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for LERC (Limited Error Raster Compression)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

LIB_DEPENDS=	libLerc.so:graphics/lerc

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

WRKSRC_SUBDIR=	OtherLanguages/Python

GH_ACCOUNT=	Esri
USE_GITHUB=	yes

# lib/libLerc.* are not available until configure phase
post-configure:
	@${MKDIR} ${WRKSRC}/../../bin/FreeBSD/
	@${CP} ${LOCALBASE}/lib/libLerc.so.* ${WRKSRC}/../../bin/FreeBSD/

.include <bsd.port.mk>
