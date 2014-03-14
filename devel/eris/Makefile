# Created by: Janni
# $FreeBSD$

PORTNAME=	eris
PORTVERSION=	1.3.23
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Eris%201.4%20%28client%20lib%29/${PORTVERSION}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge client entity library

LIB_DEPENDS=	libAtlas-0.6.so:${PORTSDIR}/devel/atlas-devel \
		libskstream-0.3.so:${PORTSDIR}/net/skstream \
		libwfmath-1.0.so:${PORTSDIR}/math/wfmath \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libmercator-0.3.so:${PORTSDIR}/devel/mercator

CONFIGURE_ARGS= --disable-silent-rules
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig
USE_GCC=	4.7+

CXXFLAGS+=	-include wchar.h

NO_STAGE=	yes
.include <bsd.port.mk>
