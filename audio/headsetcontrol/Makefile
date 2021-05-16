# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	headsetcontrol
PORTVERSION=	2.4
CATEGORIES=	audio

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Tool to setup sidetone for various gaming headsets

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	hidapi>=0:comms/hidapi
LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	Sapd
GH_PROJECT=	HeadsetControl

PLIST_FILES=	${LOCALBASE}/bin/headsetcontrol

.include <bsd.port.mk>
