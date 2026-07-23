PORTNAME=	headsetcontrol
DISTVERSION=	4.0.0
CATEGORIES=	audio

MAINTAINER=	avereeken@fastmail.de
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

PLIST_FILES=	bin/headsetcontrol \
		include/headsetcontrol/device.hpp \
		include/headsetcontrol/headsetcontrol.hpp \
		include/headsetcontrol/headsetcontrol_c.h \
		include/headsetcontrol/result_types.hpp \
		lib/libheadsetcontrol.a

.include <bsd.port.mk>
