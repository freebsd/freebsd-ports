# $FreeBSD$

PORTNAME=	openobex
PORTVERSION=	1.7.1
CATEGORIES=	comms net
MASTER_SITES=	http://www.hendrik-sattler.de/downloads/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source implementation of the OBEX protocol

USE_LDCONFIG=	yes
USES=		pathfix cmake
USE_DOS2UNIX=	CMakeLists.txt
CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR:STRING="${PREFIX}/libdata/pkgconfig"

OPTIONS_DEFINE=	DOXYGEN

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	DOXYGEN
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOXYGEN=""
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
PLIST_SUB+=	DOXYGEN="@comment "
.endif

.include <bsd.port.mk>
