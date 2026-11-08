PORTNAME=	pydnstable
PORTVERSION=	0.8.1
CATEGORIES=	dns python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for dns/dnstable
WWW=		https://github.com/farsightsec/pydnstable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libmtbl.so:devel/mtbl \
		libdnstable.so:dns/dnstable

USES=		pkgconfig python
USE_PYTHON=	autoplist cython pep517

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/dnstable*.so

.include <bsd.port.mk>
