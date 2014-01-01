# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	mongo-cxx-driver
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	waitman@waitman.net
COMMENT=	C++ 2.4 Driver for MongoDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	41691d5

USE_PYTHON_BUILD=	2

NO_STAGE=	yes
.include <bsd.port.mk>
