# $FreeBSD$

PORTNAME=	direwolf
PORTVERSION=	1.4
CATEGORIES=	comms hamradio

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Software software "soundcard" modem/TNC and APRS encoder/decoder

LICENSE=	GPLv2

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
		libgpsd.so:astro/gpsd

USE_GITHUB=	yes
GH_ACCOUNT=	wb2osz
GH_PROJECT=	direwolf
GH_TAGNAME=	6207e2e
USES=		dos2unix gmake shebangfix

SHEBANG_FILES=	telemetry-toolkit/telem-bits.pl telemetry-toolkit/telem-parm.pl\
		telemetry-toolkit/telem-eqns.pl dwespeak.sh \
		telemetry-toolkit/telem-volts.py telemetry-toolkit/telem-data.pl \
		telemetry-toolkit/telem-data91.pl \
		telemetry-toolkit/telem-unit.pl	telemetry-toolkit/telem-balloon.pl

pre-patch:
	${CP}	${FILESDIR}/Makefile.FreeBSD ${WRKSRC}
	${REINPLACE_CMD} -e 's|%%STAGEDIR%%|${STAGEDIR}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			${WRKSRC}/Makefile.FreeBSD

post-install:
.for	f in direwolf decode_aprsd text2tt tt2text ll2utm utm2ll aclients \
	log2gpx gen_packets atest ttcalc \
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/direwolf/$f
.endfor

.include <bsd.port.mk>
