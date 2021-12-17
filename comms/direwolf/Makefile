PORTNAME=	direwolf
DISTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software "soundcard" modem/TNC and APRS encoder/decoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib\
		libhamlib.so:comms/hamlib \
		libgps.so:astro/gpsd \
		libportaudio.so:audio/portaudio
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:noninja python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	wb2osz
GH_TAGNAME=	1.6

SHEBANG_FILES=	scripts/telemetry-toolkit/telem-bits.pl \
		scripts/telemetry-toolkit/telem-parm.pl\
		scripts/telemetry-toolkit/telem-eqns.pl \
		scripts/dwespeak.sh \
		scripts/telemetry-toolkit/telem-data.pl \
		scripts/telemetry-toolkit/telem-data91.pl \
		scripts/telemetry-toolkit/telem-unit.pl	\
		scripts/telemetry-toolkit/telem-balloon.pl\
		scripts/dw-start.sh \
		scripts/telemetry-toolkit/telem-volts.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'\
		${WRKSRC}/scripts/dw-start.sh

.include <bsd.port.mk>
