# $FreeBSD$

PORTNAME=	openobex
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	http://www.hendrik-sattler.de/downloads/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source implementation of the OBEX protocol

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
MAKE_JOBS_SAFE=	yes
USE_DOS2UNIX=	CMakeLists.txt
CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR:STRING="${PREFIX}/libdata/pkgconfig"

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=	DOXYGEN

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOXYGEN=""
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
PLIST_SUB+=	DOXYGEN="@comment "
.endif

.include <bsd.port.mk>
