PORTNAME=	direwolf
DISTVERSION=	1.8
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software "soundcard" modem/TNC and APRS encoder/decoder
WWW=		https://github.com/wb2osz/direwolf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgps.so:astro/gpsd \
		libhamlib.so:comms/hamlib \
		libportaudio.so:audio/portaudio
RUN_DEPENDS=	bash:shells/bash

USES=		cmake pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	wb2osz

SHEBANG_FILES=	scripts

TARGET_ORDER_OVERRIDE=	610:fix-shebang

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/scripts/dw-start.sh

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
