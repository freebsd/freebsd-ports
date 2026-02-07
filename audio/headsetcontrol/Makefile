PORTNAME=	headsetcontrol
DISTVERSION=	3.1.0
CATEGORIES=	audio

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Tool to control certain aspects of USB-connected headsets
WWW=		https://github.com/Sapd/HeadsetControl

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	hidapi>=0:comms/hidapi
LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	Sapd
GH_PROJECT=	HeadsetControl

PLIST_FILES=	bin/headsetcontrol

.include <bsd.port.mk>
