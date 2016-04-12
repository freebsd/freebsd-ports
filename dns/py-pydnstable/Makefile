# $FreeBSD$

PORTNAME=	pydnstable
PORTVERSION=	0.6.0
CATEGORIES=	dns python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for dns/dnstable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libdnstable.so:dns/dnstable

USE_PYTHON=	autoplist distutils
USES=		pkgconfig python

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/dnstable.so

.include <bsd.port.mk>
