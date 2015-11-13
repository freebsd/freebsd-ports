# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	mongo-cxx-driver
PORTVERSION=	1.0.5
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	numisemis@yahoo.com
COMMENT=	C++ Driver for MongoDB

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs

MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-cxx-driver
GH_TAGNAME=	e849f94

WRKSRC=		${WRKDIR}/mongo-cxx-driver-e849f94
USES=		execinfo scons
MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--cc=${CC} \
		--cxx=${CXX}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
