PORTNAME=	direwolf
DISTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software "soundcard" modem/TNC and APRS encoder/decoder
WWW=		https://github.com/wb2osz/direwolf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib\
		libgps.so:astro/gpsd \
		libhamlib.so:comms/hamlib \
		libportaudio.so:audio/portaudio
RUN_DEPENDS=	bash:shells/bash

USES=		cmake python shebangfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wb2osz

SHEBANG_FILES=	scripts
TARGET_ORDER_OVERRIDE=	610:fix-shebang

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g'\
		-e 's|/var/tmp|/var/log|' ${WRKSRC}/scripts/dw-start.sh

.include <bsd.port.mk>
