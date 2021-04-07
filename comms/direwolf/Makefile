PORTNAME=	direwolf
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software "soundcard" modem/TNC and APRS encoder/decoder

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:audio/alsa-lib\
		libhamlib.so:comms/hamlib \
		libgps.so:astro/gpsd

USES=		gmake python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	wb2osz
GH_TAGNAME=	1.5

SHEBANG_FILES=	telemetry-toolkit/telem-bits.pl telemetry-toolkit/telem-parm.pl\
		telemetry-toolkit/telem-eqns.pl dwespeak.sh \
		telemetry-toolkit/telem-volts.py telemetry-toolkit/telem-data.pl \
		telemetry-toolkit/telem-data91.pl \
		telemetry-toolkit/telem-unit.pl	telemetry-toolkit/telem-balloon.pl\
		dw-start.sh

OPTIONS_DEFINE=	DOCS EXAMPLES
MAKEFILE=	Makefile.linux

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'\
		-e 's|/var/tmp|/var/log|' ${WRKSRC}/dw-start.sh

.include <bsd.port.mk>
