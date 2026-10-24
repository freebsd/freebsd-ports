PORTNAME=	pywdns
PORTVERSION=	0.10.2
PORTREVISION=	2
CATEGORIES=	dns python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for dns/wdns
WWW=		https://github.com/farsightsec/pywdns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libwdns.so:dns/wdns

USES=		pkgconfig python
USE_PYTHON=	autoplist cython pep517

post-patch:
	${REINPLACE_CMD} -e "1s+/usr/bin/python+ ${PYTHON_CMD}+" ${WRKSRC}/gen_pywdns_constants

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/wdns*.so

.include <bsd.port.mk>
