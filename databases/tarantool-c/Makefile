# $FreeBSD$

PORTNAME=	tarantool-c
PORTVERSION=	1.0.0
CATEGORIES=	databases

MAINTAINER=	vg@FreeBSD.org
COMMENT=	C client for Tarantool 1.6+

LIB_DEPENDS=	libmsgpuck.so:${PORTSDIR}/devel/msgpuck

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}
GH_ACCOUNT=	tarantool
GH_TAGNAME=	8704f4a

USES=		cmake
CMAKE_ARGS=	-DENABLE_BUNDLED_MSGPUCK=false

.include <bsd.port.mk>
