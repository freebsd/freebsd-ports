# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	mongo-cxx-driver
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	waitman@waitman.net
COMMENT=	C++ 2.4 Driver for MongoDB

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		sasl2:${PORTSDIR}/security/cyrus-sasl2

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	41691d5

USE_PYTHON=	yes

.include <bsd.port.mk>
