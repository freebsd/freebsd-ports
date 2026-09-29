PORTNAME=	pylerc
PORTVERSION=	4.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Limited Error Raster Compression
WWW=		https://esri.github.io/lerc/ \
		https://github.com/Esri/lerc/tree/master/OtherLanguages/Python \
		https://github.com/Esri/lerc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libLerc.so:graphics/lerc

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

WRKSRC_SUBDIR=	OtherLanguages/Python

USE_GITHUB=	yes
GH_ACCOUNT=	Esri
GH_PROJECT=	lerc

# lib/libLerc.* are not available until configure phase
post-configure:
	@${CP} ${LOCALBASE}/lib/libLerc.so.* ${WRKSRC}/lerc/

.include <bsd.port.mk>
