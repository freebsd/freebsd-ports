# $FreeBSD$

PORTNAME=	bladeRF
DISTVERSION=	2018.12
DISTVERSIONSUFFIX=	-rc2
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BladeRF USB 3.0 Superspeed software defined radio

LICENSE=	MIT LGPL20 GPLv2
LICENSE_COMB=	multi

USES=		cmake compiler:c11 libedit
USE_GITHUB=	yes
GH_ACCOUNT=	Nuand
GH_TUPLE=	analogdevicesinc:no-OS:0bba46e:x/thirdparty/analogdevicesinc/no-OS
USE_LDCONFIG=	yes

PLIST_FILES=	bin/bladeRF-cli \
		bin/bladeRF-fsk \
		include/bladeRF1.h \
		include/bladeRF2.h \
		include/libbladeRF.h \
		lib/libbladeRF.so \
		lib/libbladeRF.so.2 \
		libdata/pkgconfig/libbladeRF.pc

.include <bsd.port.mk>
