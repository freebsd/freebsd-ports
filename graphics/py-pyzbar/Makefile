PORTNAME=	pyzbar
PORTVERSION=	0.1.9
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Read one-dimensional barcodes and qr codes from python 2 and 3
WWW=		https://github.com/NaturalHistoryMuseum/pyzbar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libzbar.so:graphics/zbar

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	NaturalHistoryMuseum
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
