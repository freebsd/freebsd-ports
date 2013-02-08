# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	cocaine-core
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH GHC

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Cocaine Application Engine

LICENSE=	GPLv3

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost-libs \
		ev:${PORTSDIR}/devel/libev \
		ltdl:${PORTSDIR}/devel/libltdl \
		msgpack:${PORTSDIR}/devel/msgpack \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		zmq:${PORTSDIR}/devel/zmq

USE_CMAKE=	yes
USE_GCC=	4.6+
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_COMMIT=	7d0f35c
GH_TAGNAME=	master

MAKE_JOBS_SAFE=	yes

CONFLICTS=	json-c-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e "s,boost_thread,boost_thread ${PTHREAD_LIBS},g" \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
