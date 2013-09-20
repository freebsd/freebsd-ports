# Created by: ijliao
# $FreeBSD$

PORTNAME=	libshbuf
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libshbuf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for Shared Buffer IPC

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOXYGEN

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=	pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-lynx

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
CONFIGURE_ARGS+=	--enable-doxygen
BUILD_DEPENDS+=	doxygen>0:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doxygen
.endif

.include <bsd.port.mk>
