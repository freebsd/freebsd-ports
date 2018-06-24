# $FreeBSD$

PORTNAME=	airspy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.9-18
DISTVERSIONSUFFIX=	-gbfb6670
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AirSpy's usemode driver and associated tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/airspy-tools/LICENSE.md

BROKEN_FreeBSD_10=	error: use of undeclared identifier '__m128'

USES=		cmake:outsource pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	airspyone_host
USE_LDCONFIG=	yes

CMAKE_OFF=	INSTALL_UDEV_RULES
CMAKE_ARGS=	-DLIBUSB_LIBRARIES="/usr/lib/libusb.so"

.include <bsd.port.mk>
