PORTNAME=	bladeRF
DISTVERSION=	2024.05
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BladeRF USB 3.0 Superspeed software defined radio
WWW=		https://www.nuand.com/

LICENSE=	MIT LGPL20 GPLv2
LICENSE_COMB=	multi

USES=		cmake compiler:c11 libedit
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Nuand
GH_TUPLE=	analogdevicesinc:no-OS:0bba46e:x/thirdparty/analogdevicesinc/no-OS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.include <bsd.port.post.mk>
