PORTNAME=	bladeRF
DISTVERSION=	2025.10
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BladeRF USB 3.0 Superspeed software defined radio
WWW=		https://www.nuand.com/ \
		https://github.com/Nuand/bladeRF/

LICENSE=	GPLv2 LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/legal/licenses/LICENSE.GPLv2
LICENSE_FILE_LGPL21=	${WRKSRC}/legal/licenses/LICENSE.LGPLv2.1
LICENSE_FILE_MIT=	${WRKSRC}/legal/licenses/LICENSE.MIT.nuand

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c11 libedit ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Nuand
GH_TUPLE=	Nuand:bladeRF-fsk:fb903684:bladerffsk/host/utilities/bladeRF-fsk \
		analogdevicesinc:no-OS:0bba46e6:noos/thirdparty/analogdevicesinc/no-OS
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCURSES_INCLUDE_PATH="${NCURSESINC}"

.include <bsd.port.mk>
