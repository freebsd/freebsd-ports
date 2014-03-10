# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cocaine-core
PORTVERSION=	0.10
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	GH GHC

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Cocaine Application Engine

LICENSE=	GPLv3

BROKEN=		Does not build

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs \
		libev.so:${PORTSDIR}/devel/libev \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libmsgpack.so:${PORTSDIR}/devel/msgpack \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libzmq.so:${PORTSDIR}/net/libzmq2

USES=		cmake
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_COMMIT=	7d0f35c
GH_TAGNAME=	${GH_COMMIT}

CONFLICTS=	json-c-[0-9]*

.include <bsd.port.mk>
