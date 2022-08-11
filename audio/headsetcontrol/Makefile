PORTNAME=	headsetcontrol
DISTVERSION=	2.6.1
CATEGORIES=	audio

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Tool to control certain aspects of USB-connected headsets

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	hidapi>=0:comms/hidapi
LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	Sapd
GH_PROJECT=	HeadsetControl
GH_TAGNAME=	5deb75a

PLIST_FILES=	${LOCALBASE}/bin/headsetcontrol

.include <bsd.port.mk>
