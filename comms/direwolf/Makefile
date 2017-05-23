# $FreeBSD$

PORTNAME=	direwolf
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Software "soundcard" modem/TNC and APRS encoder/decoder

LICENSE=	GPLv2

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
		libgps.so:astro/gpsd

USE_GITHUB=	yes
GH_ACCOUNT=	wb2osz
GH_TAGNAME=	6207e2e
USES=		dos2unix gmake python shebangfix

SHEBANG_FILES=	telemetry-toolkit/telem-bits.pl telemetry-toolkit/telem-parm.pl\
		telemetry-toolkit/telem-eqns.pl dwespeak.sh \
		telemetry-toolkit/telem-volts.py telemetry-toolkit/telem-data.pl \
		telemetry-toolkit/telem-data91.pl \
		telemetry-toolkit/telem-unit.pl	telemetry-toolkit/telem-balloon.pl

post-patch:
	${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/dw-start.sh

.include <bsd.port.mk>
