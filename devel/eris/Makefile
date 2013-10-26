# Created by: Janni
# $FreeBSD$

PORTNAME=	eris
PORTVERSION=	1.3.21
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Eris%201.4%20%28client%20lib%29/${PORTVERSION}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge client entity library

LIB_DEPENDS=	Atlas-0.6.1:${PORTSDIR}/devel/atlas-devel \
		skstream-0.3.7:${PORTSDIR}/net/skstream \
		wfmath-1.0.1:${PORTSDIR}/math/wfmath \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		mercator-0.3.3:${PORTSDIR}/devel/mercator

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	pathfix pkgconfig
USE_GCC=	yes

CXXFLAGS+=	-include wchar.h
CONFIGURE_ARGS+="CXXFLAGS=${CXXFLAGS}"

NO_STAGE=	yes
.include <bsd.port.mk>
