# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	headsetcontrol
PORTVERSION=	2.3
CATEGORIES=	audio

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Tool to setup sidetone for various gaming headsets

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	hidapi>=0:comms/hidapi
LIB_DEPENDS+=	libhidapi.so:comms/hidapi

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	Sapd
GH_PROJECT=	HeadsetControl

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/udev/|/usr/local/etc/udev/|g' ${WRKSRC}/CMakeLists.txt

PLIST_FILES=	${LOCALBASE}/bin/headsetcontrol \
		${LOCALBASE}/etc/udev/rules.d/50-corsair-void-pro-usb.rules \
		${LOCALBASE}/etc/udev/rules.d/50-corsair-void-pro.rules \
		${LOCALBASE}/etc/udev/rules.d/50-corsair-void.rules \
		${LOCALBASE}/etc/udev/rules.d/50-corsair_void_rgb_usb.rules \
		${LOCALBASE}/etc/udev/rules.d/50-logitech-g430.rules \
		${LOCALBASE}/etc/udev/rules.d/50-logitech-g533.rules \
		${LOCALBASE}/etc/udev/rules.d/50-logitech-g633.rules \
		${LOCALBASE}/etc/udev/rules.d/50-logitech-g930.rules \
		${LOCALBASE}/etc/udev/rules.d/50-logitech-g933.rules \
		${LOCALBASE}/etc/udev/rules.d/50-logitech-g935.rules \
		${LOCALBASE}/etc/udev/rules.d/50-steelseries-arctis-7-2019.rules \
		${LOCALBASE}/etc/udev/rules.d/50-steelseries-arctis-7.rules \
		${LOCALBASE}/etc/udev/rules.d/50-steelseries-arctis-pro-2019.rules

.include <bsd.port.mk>
