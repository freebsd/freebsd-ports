PORTNAME=	adns
DISTVERSION=	1.6.0
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}_python

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Python module to resolve IPs to host names
WWW=		https://github.com/trolldbois/python3-adns/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

LIB_DEPENDS=	libadns.so:dns/adns

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/adns*.so

.include <bsd.port.mk>
