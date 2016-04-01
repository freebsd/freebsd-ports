# $FreeBSD$

PORTNAME=	openobex
PORTVERSION=	1.7.1
PORTREVISION=	2
CATEGORIES=	comms net
MASTER_SITES=	SF \
		http://www.hendrik-sattler.de/downloads/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source implementation of the OBEX protocol

USE_LDCONFIG=	yes
USES=		cmake dos2unix
DOS2UNIX_FILES=	CMakeLists.txt
CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR:STRING="${PREFIX}/libdata/pkgconfig"

OPTIONS_DEFINE=	DOXYGEN

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	DOXYGEN
.endif

OPTIONS_SUB=yes
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_OFF=	-DBUILD_DOCUMENTATION=OFF

.include <bsd.port.mk>
