PORTNAME=	direwolf
DISTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	comms hamradio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	a30f90956b81feeb65007828c27617df1ce9f052.patch:-p1 \
		e449e39d4d0fba994b1a48aad13c40cd5e44a959.patch:-p1 \
		6bfd22811c329539111ed72bafc1d18514af8a74.patch:-p1 \
		5dbe2ce136fbe75dcfed49583fb62e2b394293c1.patch:-p1 \
		42314b7219ec266697396c7a4b61afe91be9b92c.patch:-p1 \
		27019b479344c1eb7cdf0a5c2dbfc54471ed4379.patch:-p1

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software "soundcard" modem/TNC and APRS encoder/decoder

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
